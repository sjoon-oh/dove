#pragma once
/* Project dove
 * Author: Sukjoon Oh (sjoon@kaist.ac.kr)
 * https://github.com/sjoon-oh/
 */

#include <cstdint>

#include <fstream>
#include <functional>

#include <string>
#include <memory>

#include <vector>

#include <unistd.h>
#include <fcntl.h>
#include <linux/aio_abi.h>

#include "./DoveMeta.hh"
#include "./DoveStopWatch.hh"


#ifdef __cplusplus
extern "C" {
#endif

int doveFileReaderDummy();

#ifdef __cplusplus
}
#endif


namespace dove {

    class FileReader {
    private:
    protected:
        std::unique_ptr<std::string> file_path;
        std::unique_ptr<std::fstream> file_handle;

        // size_t file_sz;
        struct DoveFileMetadata file_meta;
        
    public:
        virtual void setFilePath(const char*);
        virtual void setFilePath(std::string&);
    
        virtual const char* getFilePath() const;

        virtual uint64_t testOpenFile() = 0;
        virtual bool openFile() = 0;

        FileReader() = default;
        virtual ~FileReader() = default;

        virtual const uint64_t tryReads(uint32_t, uint32_t) = 0;
    };

    
    // 
    namespace async {

        class FileRandomReader : public FileReader {
        private:
        protected:
            bool file_open;
            int file_d;

            aio_context_t file_aio_ctx;
            std::unique_ptr<StopWatch> stop_watch;

            virtual void contextSetup();
            virtual void stopWatchSetup();

        public:
            FileRandomReader();
            FileRandomReader(const char*);
            FileRandomReader(std::string&);
            virtual ~FileRandomReader();

            virtual uint64_t testOpenFile();
            virtual bool openFile();

            virtual const uint64_t tryReads(uint32_t, uint32_t);
        };
    };
}


#pragma endregion File Generator