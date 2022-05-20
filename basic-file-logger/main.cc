#include <iostream>

#include "spdlog/sinks/basic_file_sink.h"
void basic_logfile_example()
{
    try
    {
        auto my_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
    }
    catch (const spdlog::spdlog_ex &ex)
    {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    basic_logfile_example();
    return 0;
}
