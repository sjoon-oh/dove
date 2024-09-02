#pragma once

/* Project dove
 * Author: Sukjoon Oh (sjoon@kaist.ac.kr)
 * https://github.com/sjoon-oh/
 */

#include <string>

#include <assert.h>
#include <stdlib.h>

#include "../extern/spdlog/spdlog.h"
#include "./includes/DoveLogger.hh"

dove::Logger::Logger(const char* lg_name) {
    logger_name = std::string(lg_name);
    logger = spdlog::stdout_color_mt(logger_name).get();
    spdlog::set_pattern("[%n:%^%l%$] %v");
}


spdlog::logger* dove::Logger::getLogger() {
    return logger;
};