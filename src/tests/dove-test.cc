/* Project dove
 * Author: Sukjoon Oh (sjoon@kaist.ac.kr)
 * https://github.com/sjoon-oh/
 */

#include <memory>
#include <iostream>

#include "../includes/DoveFileGenerator.hh"
#include "../includes/DoveFileReader.hh"
#include "../includes/DoveStopWatch.hh"
#include "../includes/DoveLogger.hh"


int main() {

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


    logger->getLogger()->info("Stopwatch: stopwatch-msec test.");
    std::unique_ptr<dove::StopWatch> stopwatch(
        new dove::StopWatchMilliseconds("data/stopwatches/stopwatch-msec"));

    for (int test_iterator = 0; test_iterator < 100; test_iterator++) {

        stopwatch->markCurrentTime();
        usleep(100);
        stopwatch->markCurrentTime();
    }

    stopwatch.reset(
        new dove::StopWatchMicroseconds("data/stopwatches/stopwatch-usec")
    );

    logger->getLogger()->info("Stopwatch: stopwatch-usec test.");
    for (int test_iterator = 0; test_iterator < 100; test_iterator++) {

        stopwatch->markCurrentTime();
        usleep(100);
        stopwatch->markCurrentTime();
    }

    uint64_t write_page_num = (1ULL * 1024 * 1024); // 4GB
    // uint64_t write_page_num = (1ULL * 1024 * 16); // 64MB

    file_initializer->setPageNumber(write_page_num);

    logger->getLogger()->info("File initializer path: {}", file_initializer->getFilePath());
    logger->getLogger()->info("File initializer page number to {:d}, set as {:d}", write_page_num, file_initializer->getPageNumber());

    uint64_t written_size = file_initializer->writeSeqSequential();
    
    if (write_page_num != file_initializer->getPageNumber())
        logger->getLogger()->warn("File written size mismatch.");

    std::unique_ptr<dove::FileReader> file_reader(
        new dove::async::FileRandomReader()
    );

    if (file_reader.get() != nullptr) {

        file_reader->setFilePath("data/file.bin");

        uint64_t test_size = 0;
        test_size = file_reader->testOpenFile();

        logger->getLogger()->info("Existing file size detect: {}", test_size);
        file_reader->openFile();

        int after_read = file_reader->tryReads(10000, 32, 5);
 
        logger->getLogger()->info("Number of reads: {}", after_read);
    }
    else {
        logger->getLogger()->warn("File reader not initialized.");
    }

    return 0;
}