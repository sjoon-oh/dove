#pragma once
/* Project dove
 * Author: Sukjoon Oh (sjoon@kaist.ac.kr)
 * https://github.com/sjoon-oh/
 */

#include <cstdint>

#include <fstream>

#include <string>
#include <memory>

#include "./DoveMeta.hh"


#ifdef __cplusplus
extern "C" {
#endif

int doveFileGeneratorDummy();

#ifdef __cplusplus
}
#endif

namespace dove {

    class FileInitializer {
    private:
    protected:
        std::unique_ptr<std::string> file_path;
        std::unique_ptr<std::fstream> file_handle;
        
    public:
        virtual void setFilePath(const char*) = 0;
        virtual void setFilePath(std::string&) = 0;
    
        virtual const char* getFilePath() const = 0;

        FileInitializer() = default;
        virtual ~FileInitializer() = default;

        virtual void setPageNumber(uint64_t) = 0;
        virtual const uint64_t getPageNumber() const = 0;

        virtual const uint64_t writeRandomSequential() = 0;
        virtual const uint64_t writeSeqSequential() = 0;
    };


#pragma region SingleFile

    // 
    // Impl
    class SingleFileInitializer final : public FileInitializer {
    private:
    protected:

        uint64_t page_num;
        const uint8_t write_size = 0x01;

    public:
        virtual void setFilePath(const char*);
        virtual void setFilePath(std::string&);

        virtual const char* getFilePath() const;

        SingleFileInitializer();
        SingleFileInitializer(const char*);
        SingleFileInitializer(std::string&);

        virtual ~SingleFileInitializer();

        virtual void setPageNumber(uint64_t);
        virtual const uint64_t getPageNumber() const;

        virtual const uint64_t writeRandomSequential();
        virtual const uint64_t writeSeqSequential();

    };

}


#pragma endregion File Generator