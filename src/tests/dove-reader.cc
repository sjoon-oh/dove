/* Project dove
 * Author: Sukjoon Oh (sjoon@kaist.ac.kr)
 * https://github.com/sjoon-oh/
 */

#include <memory>
#include <iostream>

#include <cstdlib>

#include "../includes/DoveFileGenerator.hh"
#include "../includes/DoveFileReader.hh"
#include "../includes/DoveStopWatch.hh"
#include "../includes/DoveLogger.hh"


int main(int argc, char** argv) {

    std::unique_ptr<dove::Logger> logger(new dove::Logger("dove-reader"));

    if (logger == nullptr) {
        return -1;
    }

    // argv[1]: file path
    // argv[2]: number of requests
    // argv[3]: number of batch reads
    // argv[4]: number of chunks

    if (argc != 5)
        return -2;
    
    std::string file_path(argv[1]);
    std::unique_ptr<dove::FileReader> file_reader(
        new dove::async::FileRandomReader()
    );

    uint32_t req_num = std::atol(argv[2]);
    uint32_t bat_num = std::atol(argv[3]);
    uint32_t chk_num = std::atol(argv[4]);

    if (file_reader.get() != nullptr) {

        file_reader->setFilePath(file_path.c_str());

        uint64_t test_size = 0;
        test_size = file_reader->testOpenFile();

        logger->getLogger()->info("Existing file size detect: {}", test_size);
        file_reader->openFile();

        int after_read = file_reader->tryReads(req_num, bat_num, chk_num);
 
        logger->getLogger()->info("Number of reads: {}", after_read);
    }
    else {
        logger->getLogger()->warn("File reader not initialized.");
    }

    return 0;
}