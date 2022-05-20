// https://github.com/gabime/spdlog/wiki/2.-Creating-loggers#creating-loggers-manually

#include "spdlog/sinks/stdout_sinks.h"

int main(int, char* [])
{
    auto sink = std::make_shared<spdlog::sinks::stdout_sink_mt>();
    auto my_logger= std::make_shared<spdlog::logger>("mylogger", sink);
}