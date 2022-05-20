// https://github.com/gabime/spdlog/wiki/2.-Creating-loggers#creating-multiple-file-loggers-with-the-same-output-file

#include "spdlog/sinks/basic_file_sink.h"

int main(int, char* [])
{
    // Различные логгеры пишут в один и тот же файл вывода.
    // Для этого все они используют совместно один и тот же sink.
    
    auto sharedFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("fileName.txt");
    auto firstLogger = std::make_shared<spdlog::logger>("firstLoggerName", sharedFileSink);
    auto secondLogger = std::make_unique<spdlog::logger>("secondLoggerName", sharedFileSink);
}
