// https://github.com/gabime/spdlog/wiki/2.-Creating-loggers#create-a-rotating-file-logger

#include "spdlog/spdlog.h"

//Create rotating file multi-threaded logger
#include "spdlog/sinks/rotating_file_sink.h"

int main(int, char* [])
{
    auto file_logger = spdlog::rotating_logger_mt("file_logger", "logs/mylogfile", 1048576 * 5, 3);
    auto same_logger= spdlog::get("file_logger");
}