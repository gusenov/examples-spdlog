// https://github.com/gabime/spdlog/wiki/1.-QuickStart

#include "spdlog/spdlog.h"

int main()
{
    // Использовать дефолтный логгер (stdout, multi-threaded, colored)
    spdlog::info("Hello, {}!", "World");
    // [2022-01-22 01:27:57.434] [info] Hello, World!
    
    // spdlog предоставляет python подобный formatting API использующий встроенный fmt lib.
    
    spdlog::info("Hello {} {} !!", "param1", 123.4);
    // [2022-01-22 01:32:01.087] [info] Hello param1 123.4 !!
}
