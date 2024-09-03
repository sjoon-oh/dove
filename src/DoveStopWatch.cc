/* Project dove
 * Author: Sukjoon Oh (sjoon@kaist.ac.kr)
 * https://github.com/sjoon-oh/
 */

#if defined(__GNUC__) && defined(__cplusplus)
#if (__GNUC__ >= 10)
#include <format>
#else
#include <cstdio>
#include <string>
#endif
#endif
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
#if defined(__GNUC__) && defined(__cplusplus)
#if (__GNUC__ >= 10)
    file_path.reset(new std::string(std::format("{}-{}.sw-intervals", p_file_path, count)));
#else
    char buffer[128] = { 0, };
    sprintf(buffer, "%s-%d.sw-intervals", p_file_path, count);
    file_path.reset(new std::string(buffer));
#endif
#endif

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

#if defined(__GNUC__) && defined(__cplusplus)
#if (__GNUC__ >= 10)
        logger.get()->getLogger()->warn(
            std::format("{} not opened.", file_path.get()->c_str()));
#else
        logger.get()->getLogger()->warn(
            (*(file_path.get()) + std::string("not opened.")).c_str());
#endif
#endif
        return;
    }

#if defined(__GNUC__) && defined(__cplusplus)
#if (__GNUC__ < 10)
    char buffer[128] = { 0, };
#endif
#endif

    for (auto& ts: *(ts_records.get())) {
        interval = calculateInterval(ts.start, ts.end);

#if defined(__GNUC__) && defined(__cplusplus)
#if (__GNUC__ >= 10)   
        out_file << std::format("{:.3f}", interval) << std::endl;
#else
        std::memset(buffer, 0, sizeof(char) * 128);
        sprintf(buffer, "%.3lf", interval);
        out_file << buffer << std::endl;
#endif
#endif
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

#if defined(__GNUC__) && defined(__cplusplus)
#if (__GNUC__ >= 10)
        logger.get()->getLogger()->warn(
            std::format("{} not opened.", file_path.get()->c_str()));
#else
        logger.get()->getLogger()->warn(
            (*(file_path.get()) + std::string("not opened.")).c_str());
#endif
#endif
        return;
    }

#if defined(__GNUC__) && defined(__cplusplus)
#if (__GNUC__ < 10)
    char buffer[128];
#endif
#endif

    for (auto& ts: *(ts_records.get())) {
        interval = calculateInterval(ts.start, ts.end);

#if defined(__GNUC__) && defined(__cplusplus)
#if (__GNUC__ >= 10)   
        out_file << std::format("{:.3f}", interval) << std::endl;
#else
        std::memset(buffer, 0, sizeof(char) * 128);
        sprintf(buffer, "%.3lf", interval);
        out_file << buffer << std::endl;
#endif
#endif
    }
}