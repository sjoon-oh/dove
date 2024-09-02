/* Project dove
 * Author: Sukjoon Oh (sjoon@kaist.ac.kr)
 * https://github.com/sjoon-oh/
 */

#include <unistd.h>
#include <random>
#include <iostream>


#include "./includes/DoveFileGenerator.hh"


#ifdef __cplusplus
extern "C" {
#endif

int doveFileGeneratorDummy() {
    return 0;
}

#ifdef __cplusplus
}
#endif

#define DEFAULT_FILE_PATH   "DEFAULT_FILE.bin"


void dove::SingleFileInitializer::setFilePath(const char* p_file_path) {
    file_path.reset(new std::string(p_file_path));
}


void dove::SingleFileInitializer::setFilePath(std::string& p_file_path) {
    setFilePath(p_file_path.c_str());
}


const char* dove::SingleFileInitializer::getFilePath() const {
    return const_cast<const char*>(file_path.get()->c_str());
}


dove::SingleFileInitializer::SingleFileInitializer() : page_num(0) {
    setFilePath(DEFAULT_FILE_PATH);
}


dove::SingleFileInitializer::SingleFileInitializer(const char* p_file_path) : page_num(0) {
    setFilePath(p_file_path);
}


dove::SingleFileInitializer::SingleFileInitializer(std::string& p_file_path) : page_num(0) {
    setFilePath(p_file_path.c_str());
}


dove::SingleFileInitializer::~SingleFileInitializer() {

}


void dove::SingleFileInitializer::setPageNumber(uint64_t p_num) {
    page_num = p_num;
}


const uint64_t dove::SingleFileInitializer::getPageNumber() const {
    return page_num;
}


const uint64_t dove::SingleFileInitializer::writeRandomSequential() {

    std::random_device rand_dev;

    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<uint8_t> distribution(0, 255);

    DoveFileMetadata* meta_frame = nullptr;

    uint8_t buffer[4096] = {0, };
    uint64_t written_pages = 0;

    const int page_size = 4096;

    file_handle.reset(
        new std::fstream(file_path.get()->c_str(), std::ios::binary | std::ios::out));

    if (file_handle.get()->is_open()) {

        for (written_pages = 0; written_pages < page_num; written_pages++) {

            for (int pos = 0; pos < 4096; pos++)
                buffer[pos] = distribution(generator);

            if (written_pages == 0) {
                meta_frame = reinterpret_cast<DoveFileMetadata*>(buffer);
                meta_frame->file_sz = page_num * 4096;
            }

            // Make one.
            size_t offset = written_pages * 4096;

            file_handle.get()->seekp(offset, std::ios::beg);
            file_handle.get()->write((const char*)(&buffer), 4096); // addr, write size

            if (file_handle.get()->fail() || file_handle.get()->bad())
                return written_pages;
        }
    }

    file_handle->sync();

    return written_pages;
}


const uint64_t dove::SingleFileInitializer::writeSeqSequential() {

    uint8_t seq_num = 0;
    DoveFileMetadata* meta_frame = nullptr;

    uint8_t buffer[4096] = {0, };
    uint64_t written_pages = 0;

    const int page_size = 4096;

    file_handle.reset(
        new std::fstream(file_path.get()->c_str(), std::ios::binary | std::ios::out));

    if (file_handle.get()->is_open()) {

        for (written_pages = 0; written_pages < page_num; written_pages++) {

            for (int pos = 0; pos < 4096; pos++)
                buffer[pos] = seq_num++;

            if (written_pages == 0) {
                meta_frame = reinterpret_cast<DoveFileMetadata*>(buffer);
                meta_frame->file_sz = page_num * 4096;
            }

            // Make one.
            size_t offset = written_pages * 4096;

            file_handle.get()->seekp(offset, std::ios::beg);
            file_handle.get()->write((const char*)(&buffer), 4096); // addr, write size

            if (file_handle.get()->fail() || file_handle.get()->bad())
                return written_pages;
        }
    }

    file_handle->sync();

    return written_pages;
}