// https://github.com/gabime/spdlog/wiki/1.-QuickStart#log-user-defined-objects

#include <iterator>

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h" // must be included
#include "spdlog/sinks/stdout_sinks.h"

class some_class {
    template<typename OStream>
    friend OStream &operator<<(OStream &os, const some_class& to_log);
    
public:
    int code;
};

template<typename OStream>
OStream &operator<<(OStream &os, const some_class& to_log)
{
    fmt::format_to(std::ostream_iterator<char>(os), "{:04X}", to_log.code);
    return os;
}

void custom_class_example()
{
    some_class c; c.code = 17;
    auto console = spdlog::stdout_logger_mt("console");
    console->info("custom class with operator<< using fmt: {}..", c);
    // [2022-01-22 02:29:36.187] [console] [info] custom class with operator<< using fmt: 0011..
}

int main(int, char* [])
{
    custom_class_example();
}