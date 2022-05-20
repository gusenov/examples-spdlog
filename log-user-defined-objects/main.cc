// https://github.com/gabime/spdlog/wiki/1.-QuickStart#log-user-defined-objects

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h" // must be included
#include "spdlog/sinks/stdout_sinks.h"

class some_class {};
std::ostream& operator<<(std::ostream& os, const some_class& c)
{ 
    return os << "some_class"; 
}

void custom_class_example()
{
    some_class c;
    auto console = spdlog::stdout_logger_mt("console");
    console->info("custom class with operator<<: {}..", c);
    // [2022-01-22 02:21:09.426] [console] [info] custom class with operator<<: some_class..
}

int main(int, char* [])
{
    custom_class_example();
}