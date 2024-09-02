#pragma once
/* Project dove
 * Author: Sukjoon Oh (sjoon@kaist.ac.kr)
 * https://github.com/sjoon-oh/
 */

#include <cstdint>

#include <string>
#include <vector>

#include <atomic>
#include <memory>

#include <chrono>

#pragma region Stopwatch


#ifdef __cplusplus
extern "C" {
#endif

// Declared, but undefined.
int doveFileStopWatchDummy();

#ifdef __cplusplus
}
#endif


namespace dove {

    class StopWatch {
    protected:
        static std::atomic_int sw_counter;
        std::unique_ptr<std::string> file_path;

        bool start_record;

        struct Interval {
            std::chrono::steady_clock::time_point start;
            std::chrono::steady_clock::time_point end;

            Interval(
                    std::chrono::steady_clock::time_point p_start
                ) : start(p_start) {
            }
        };

        std::unique_ptr<std::vector<struct Interval>> ts_records;
        std::unique_ptr<std::vector<double>> ts_intervals;

    public:
        StopWatch();
        StopWatch(const char*);
        virtual ~StopWatch();
    
        virtual bool markCurrentTime();
        virtual double calculateInterval(
            std::chrono::steady_clock::time_point, 
            std::chrono::steady_clock::time_point) = 0;
    };

    // 
    class StopWatchMilliseconds final : public StopWatch {
    private:
    public:
        StopWatchMilliseconds();
        StopWatchMilliseconds(const char*);
        virtual ~StopWatchMilliseconds();

        virtual double calculateInterval(
            std::chrono::steady_clock::time_point, 
            std::chrono::steady_clock::time_point);
    };

    class StopWatchMicroseconds final : public StopWatch {
    private:
    public:
        StopWatchMicroseconds();
        StopWatchMicroseconds(const char*);
        virtual ~StopWatchMicroseconds();

        virtual double calculateInterval(
            std::chrono::steady_clock::time_point, 
            std::chrono::steady_clock::time_point);
    };

}



#pragma endregion Stopwatch