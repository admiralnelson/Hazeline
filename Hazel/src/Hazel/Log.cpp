#include "Log.h"


namespace Hazel
{
    std::shared_ptr<spdlog::logger> Log::sCoreLogger;
    std::shared_ptr<spdlog::logger> Log::sClientLoggger;
    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        sCoreLogger = spdlog::stdout_color_mt("Hazel");
        sCoreLogger->set_level(spdlog::level::trace);

        sClientLoggger = spdlog::stdout_color_mt("Program");
        sCoreLogger->set_level(spdlog::level::trace);
    }
}
