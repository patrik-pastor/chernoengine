//
// Created by shepherd on 6.3.23.
//

#ifndef CHERNOENGINE_LOG_HPP
#define CHERNOENGINE_LOG_HPP

#include <memory>

#include <spdlog/spdlog.h>

namespace chernoengine {

class Log {
public:
    static void Init();

    static std::shared_ptr<spdlog::logger> &getCoreLogger();

    static std::shared_ptr<spdlog::logger> &getClientLogger();

private:
    static std::shared_ptr<spdlog::logger> core_logger;
    static std::shared_ptr<spdlog::logger> client_logger;
};

} // chernoengine

#define CORE_FATAL(...) chernoengine::Log::getCoreLogger()->fatal(__VA_ARGS__)
#define CORE_ERROR(...) chernoengine::Log::getCoreLogger()->error(__VA_ARGS__)
#define CORE_WARN(...) chernoengine::Log::getCoreLogger()->warn(__VA_ARGS__)
#define CORE_INFO(...) chernoengine::Log::getCoreLogger()->info(__VA_ARGS__)
#define CORE_TRACE(...) chernoengine::Log::getCoreLogger()->trace(__VA_ARGS__)

#define CLIENT_FATAL(...) chernoengine::Log::getClientLogger()->fatal(__VA_ARGS__)
#define CLIENT_ERROR(...) chernoengine::Log::getClientLogger()->error(__VA_ARGS__)
#define CLIENT_WARN(...) chernoengine::Log::getClientLogger()->warn(__VA_ARGS__)
#define CLIENT_INFO(...) chernoengine::Log::getClientLogger()->info(__VA_ARGS__)
#define CLIENT_TRACE(...) chernoengine::Log::getClientLogger()->trace(__VA_ARGS__)

#endif //CHERNOENGINE_LOG_HPP
