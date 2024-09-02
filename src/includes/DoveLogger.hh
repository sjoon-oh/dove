#pragma once
/* Project dove
 * Author: Sukjoon Oh (sjoon@kaist.ac.kr)
 * https://github.com/sjoon-oh/
 */

#include <string>

#include "../../extern/spdlog/spdlog.h"
#include "../../extern/spdlog/sinks/stdout_color_sinks.h"
#include "../../extern/spdlog/sinks/basic_file_sink.h"

namespace dove {

    class Logger {
        std::string logger_name;
        spdlog::logger* logger;
    
    public:
        Logger(const char*);

        spdlog::logger* getLogger();
    };
}