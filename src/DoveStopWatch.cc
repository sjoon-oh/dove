/* Project dove
 * Author: Sukjoon Oh (sjoon@kaist.ac.kr)
 * https://github.com/sjoon-oh/
 */

#include <format>
#include <fstream>

#include "./includes/DoveStopWatch.hh"
#include "./includes/DoveLogger.hh"

#pragma region Stopwatch


#ifdef __cplusplus
extern "C" {
#endif

// Declared, but undefined.
int doveFileStopWatchDummy() {
    return 0;
}

#ifdef __cplusplus
}
#endif

#define DEFAULT_SWFILE_PATH "STOPWATCH_FILE"

// Initialized
std::atomic_int dove::StopWatch::sw_counter{0};


dove::StopWatch::StopWatch() : start_record(true) {
    sw_counter.fetch_add(1);
    
    file_path.reset(new std::string(DEFAULT_SWFILE_PATH));
    ts_records.reset(new std::vector<struct dove::StopWatch::Interval>());
}


dove::StopWatch::StopWatch(const char* p_file_path) : start_record(true) {
    
    int count = sw_counter.fetch_add(1);

    file_path.reset(new std::string(std::format("{}-{}.sw-intervals", p_file_path, count)));
    ts_records.reset(new std::vector<struct dove::StopWatch::Interval>());
}


dove::StopWatch::~StopWatch() {
    
}


bool dove::StopWatch::markCurrentTime() {

    if (start_record) {
        ts_records.get()->push_back(
            dove::StopWatch::Interval(std::chrono::steady_clock::now())
        );
        start_record = false;
    }
    else {
        ts_records.get()->back().end = std::chrono::steady_clock::now();
        start_record = true;
    }

    return start_record;
}

#pragma endregion Stopwatch


dove::StopWatchMilliseconds::StopWatchMilliseconds()
    : dove::StopWatch::StopWatch() {

}


dove::StopWatchMilliseconds::StopWatchMilliseconds(const char* p_file_path)
    : dove::StopWatch::StopWatch(p_file_path) {
    
}


double dove::StopWatchMilliseconds::calculateInterval(
        std::chrono::steady_clock::time_point p_start,
        std::chrono::steady_clock::time_point p_end
    ) {

    return (std::chrono::duration_cast<std::chrono::microseconds>(p_end - p_start).count() * 1.0) / 1000.0;
}


dove::StopWatchMilliseconds::~StopWatchMilliseconds() {
    std::ofstream out_file(file_path.get()->c_str());
    
    double interval;

    std::unique_ptr<dove::Logger> logger(new dove::Logger(file_path.get()->c_str()));

    if (!out_file.is_open()) {
        logger.get()->getLogger()->warn(
            std::format("{} not opened.", file_path.get()->c_str()));
        return;
    }

    for (auto& ts: *(ts_records.get())) {
        interval = calculateInterval(ts.start, ts.end);
        out_file << std::format("{:.3f}", interval) << std::endl;
    }
}


dove::StopWatchMicroseconds::StopWatchMicroseconds()
    : dove::StopWatch::StopWatch() {

}


dove::StopWatchMicroseconds::StopWatchMicroseconds(const char* p_file_path)
    : dove::StopWatch::StopWatch(p_file_path) {
    
}


double dove::StopWatchMicroseconds::calculateInterval(
        std::chrono::steady_clock::time_point p_start,
        std::chrono::steady_clock::time_point p_end
    ) {

    return (std::chrono::duration_cast<std::chrono::nanoseconds>(p_end - p_start).count() * 1.0) / 1000.0;
}


dove::StopWatchMicroseconds::~StopWatchMicroseconds() {
    std::ofstream out_file(file_path.get()->c_str());
    
    double interval;

    std::unique_ptr<dove::Logger> logger(new dove::Logger(file_path.get()->c_str()));

    if (!out_file.is_open()) {
        logger.get()->getLogger()->warn(
            std::format("{} not opened.", file_path.get()->c_str()));
        return;
    }

    for (auto& ts: *(ts_records.get())) {
        interval = calculateInterval(ts.start, ts.end);
        out_file << std::format("{:.3f}", interval) << std::endl;
    }
}