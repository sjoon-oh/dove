/* Project dove
 * Author: Sukjoon Oh (sjoon@kaist.ac.kr)
 * https://github.com/sjoon-oh/
 */

#include <unistd.h>
#include <sys/syscall.h>

#include <cstring>
#include <memory>

#if defined(__GNUC__) && defined(__cplusplus)
#if (__GNUC__ >= 10)
#include <format>
#else
#include <cstdio>
#include <string>
#endif
#endif

#include <random>

#include <iostream>

#include "./includes/DoveParam.hh"
#include "./includes/DoveFileReader.hh"

#ifdef __cplusplus
extern "C" {
#endif

int doveFileReaderDummy() {
    return 0;
}

#ifdef __cplusplus
}
#endif


#define DEFAULT_FILE_PATH   "DEFAULT_FILE.bin"

void dove::FileReader::setFilePath(const char* p_file_path) {
    file_path.reset(new std::string(p_file_path));
}


void dove::FileReader::setFilePath(std::string& p_file_path) {
    setFilePath(p_file_path.c_str());
}


const char* dove::FileReader::getFilePath() const {
    return const_cast<const char*>(file_path.get()->c_str());
}


#pragma region Async FileRandomReader
void dove::async::FileRandomReader::contextSetup() {
    std::memset(&file_aio_ctx, 0, sizeof(aio_context_t));
    if (syscall(__NR_io_setup, (int)MAX_IO_SIZE, &file_aio_ctx) < 0)
        perror("AIO setup fail");
}


void dove::async::FileRandomReader::stopWatchSetup() {

#if defined(__GNUC__) && defined(__cplusplus)
#if (__GNUC__ >= 10)
    std::string sw_name(std::format("{}", typeid(*this).name()));
    std::string sw_path(std::format("data/stopwatches/{}", sw_name));
#else
    std::string sw_name =  typeid(*this).name();
    std::string sw_path(
        std::string("data/stopwatches/") + sw_name 
    );
#endif
#endif

    stop_watch.reset(
        new dove::StopWatchMicroseconds(sw_path.c_str())
    );
}


dove::async::FileRandomReader::FileRandomReader() 
    : file_open(false), file_d(-1) {

    setFilePath(DEFAULT_FILE_PATH);
    file_meta.file_sz = 0;
}


dove::async::FileRandomReader::FileRandomReader(const char* p_file_path) 
    : file_open(false), file_d(-1) {

    setFilePath(p_file_path);
    file_meta.file_sz = 0;
}


dove::async::FileRandomReader::FileRandomReader(std::string& p_file_path)
    : file_open(false), file_d(-1) {
        
    setFilePath(p_file_path.c_str());
    file_meta.file_sz = 0;  
}


dove::async::FileRandomReader::~FileRandomReader() {

}


uint64_t dove::async::FileRandomReader::testOpenFile() {

    std::unique_ptr<std::fstream> test_openf(
        new std::fstream(
            file_path.get()->c_str(), std::ios::in | std::ios::binary)
    );
    DoveFileMetadata* meta_frame = nullptr;

    const int offset = 0;
    uint64_t file_sz = 0;

    if (test_openf->is_open()) {
        
        test_openf->seekg(offset, std::ios::beg);
        test_openf->read(reinterpret_cast<char*>(&file_sz), sizeof(uint64_t));

        return file_sz;
    }
    else {
        return 0;
    }
}


bool dove::async::FileRandomReader::openFile() {

    bool ret = false;
    file_handle.reset(
        new std::fstream(
            file_path.get()->c_str(), std::ios::in | std::ios::binary)
    );

    const int offset = 0;
    uint64_t file_sz = 0;

    if ((ret = file_handle->is_open())) {
        
        file_handle->seekg(offset, std::ios::beg);
        file_handle->read(reinterpret_cast<char*>(&file_sz), sizeof(uint64_t));

        file_meta.file_sz = file_sz;

        // std::cout << file_meta.file_sz << std::endl;

        file_handle->close();

        // open file.
        file_d = open(file_path.get()->c_str(), O_RDONLY | O_DIRECT);
    }
    else
        file_meta.file_sz = 0;

    return ret;
}


const uint64_t dove::async::FileRandomReader::tryReads(uint32_t p_num, uint32_t p_batch, uint32_t p_chunks) {

    const uint32_t page_num = (file_meta.file_sz / 4096);

    // Validate
    {  
        if (page_num == 0) return 0;
    }
   
    const uint32_t req_num = p_num;
    struct timespec aio_timeout{0, 30000};

    std::vector<struct iocb*> iocbs(req_num);
    std::vector<uint8_t*> buffs(req_num);
    
    for (int i = 0; i < req_num; i++) {
        iocbs[i] = new struct iocb[p_batch];
        buffs[i] = new uint8_t[4096 * 1024];

        std::memset(iocbs[i], 0, p_batch * sizeof(struct iocb));
    }

    const uint32_t chunk_sz = p_chunks;

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<std::uint64_t> distribution(0, page_num - chunk_sz);

    contextSetup();

    // Prepare the requests
    struct iocb* cur_iocb;
    for (int i = 0; i < req_num; i++) {

        // struct iocb* cur_head = iocbs[i];
        for (int j = 0; j < p_batch; j++) {

            cur_iocb = &(iocbs[i][j]);
                        
            cur_iocb->aio_data = reinterpret_cast<uintptr_t>(cur_iocb);
            cur_iocb->aio_lio_opcode = IOCB_CMD_PREAD;
            cur_iocb->aio_fildes = file_d;

            cur_iocb->aio_buf = reinterpret_cast<uintptr_t>(buffs[i]);
            cur_iocb->aio_offset = (distribution(generator) * 4096);
            cur_iocb->aio_nbytes = 4096 * chunk_sz;
        }
    }

    std::vector<struct io_event> events(p_batch);

    stopWatchSetup();
    if (stop_watch.get() == nullptr) {
        return 0;
    }

    for (int i = 0; i < req_num; i++) {

        // Do something
        stop_watch->markCurrentTime();

        int completed = 0;
        int submitted = 0;

        while (submitted < p_batch) {
            int submit = syscall(__NR_io_submit, file_aio_ctx, p_batch - submitted, iocbs[i] + submitted);
            if (submit < 0) {
                perror("__NR_io_submit failed");
                return 0;
            }
            
            submitted += submit;
        }

        while (completed < p_batch) {
            
            int wait = p_batch - completed;
            submitted = syscall(__NR_io_getevents, 
                file_aio_ctx, wait, wait, events.data() + completed ,&aio_timeout);
            
            if (submitted < 0) {
                perror("__NR_io_getevents failed");
                return 0;
            }
            completed += submitted;
        }

        stop_watch->markCurrentTime();

        std::memset(events.data(), 0, sizeof(struct io_event) * p_batch);
    }

    for (int i = 0; i < req_num; i++) {
        delete[] iocbs[i];
    }
    for (int i = 0; i < req_num; i++) {
        delete[] buffs[i];
    }
    
    return req_num;
}

#pragma endregion Async FileRandomReader