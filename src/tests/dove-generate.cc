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

    std::unique_ptr<dove::Logger> logger(new dove::Logger("dove-test"));

    std::unique_ptr<dove::FileInitializer> file_initializer(
        new dove::SingleFileInitializer("data/file.bin")
    );

    if (logger == nullptr) {
        return -1;
    }

    if (file_initializer == nullptr) {
        logger->getLogger()->warn("FileInitializer allocation failed.\n");
        return -2;
    }

    if (argc != 2)
        return -1;

    uint64_t write_page_num = std::atol(argv[1]);

    // uint64_t write_page_num = (1ULL * 1024 * 1024); // 4GB
    // uint64_t write_page_num = (1ULL * 1024 * 16); // 64MB

    file_initializer->setPageNumber(write_page_num);

    logger->getLogger()->info("File initializer path: {}", file_initializer->getFilePath());
    logger->getLogger()->info("File initializer page number to {:d}, set as {:d}", write_page_num, file_initializer->getPageNumber());

    uint64_t written_size = file_initializer->writeSeqSequential();
    
    return 0;
}