// https://github.com/gabime/spdlog/wiki/1.-QuickStart#logging-macros

#include <iostream>

// Можно определить SPDLOG_ACTIVE_LEVEL с желаемым log level перед включением "spdlog.h".
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
// Это вкл./выкл. logging statements на этапе компиляции.

#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h" // support for rotating file logging

int main(int, char* [])
{
    spdlog::set_level(spdlog::level::debug); 
    // or spdlog::set_level(spdlog::level::trace); 

    try 
    {
        // create a file rotating logger with 5mb size max and 3 rotated files
        auto file_logger = spdlog::rotating_logger_mt("file_logger", "myfilename", 1024 * 1024 * 5, 3);
        
        SPDLOG_LOGGER_TRACE(file_logger , "Some trace message that will not be evaluated.{} ,{}", 1, 3.23);
        SPDLOG_LOGGER_DEBUG(file_logger , "Some Debug message that will be evaluated.. {} ,{}", 1, 3.23);
        
        SPDLOG_DEBUG("Some debug message to default logger that will be evaluated");
        // [2022-01-22 02:15:22.426] [debug] [main.cc:24] Some debug message to default logger that will be evaluated
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cout << "Log initialization failed: " << ex.what() << std::endl;
    }
}