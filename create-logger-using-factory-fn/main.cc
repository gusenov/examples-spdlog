// https://github.com/gabime/spdlog/wiki/2.-Creating-loggers#creating-loggers-using-the-factory-functions

#include "spdlog/sinks/stdout_color_sinks.h"

int main(int, char* [])
{
    // Создать и вернуть shared_ptr на multithreaded console logger.
    auto console = spdlog::stdout_color_mt("some_unique_name");
    // 1) Создает console logger.
    // 2) Регистрирует его в spdlog's global registry с "some_unique_name" в качестве id.
    // 3) Возвращает его как shared_ptr.
}