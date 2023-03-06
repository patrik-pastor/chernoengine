//
// Created by shepherd on 6.3.23.
//

#include <chernoengine/logging/log.hpp>

#include <spdlog/sinks/stdout_color_sinks.h>

namespace chernoengine {

std::shared_ptr<spdlog::logger> Log::core_logger;
std::shared_ptr<spdlog::logger> Log::client_logger;

std::shared_ptr<spdlog::logger> &Log::getCoreLogger() {
    return core_logger;
}

std::shared_ptr<spdlog::logger> &Log::getClientLogger() {
    return client_logger;
}

void Log::Init() {
    spdlog::set_pattern("%^[%T] %n: %v%$");
    core_logger = spdlog::stdout_color_mt("CHERNOENGINE");
    core_logger->set_level(spdlog::level::trace);

    client_logger = spdlog::stdout_color_mt("APP");
    client_logger->set_level(spdlog::level::trace);
}

} // chernoengine