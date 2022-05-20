// https://github.com/gabime/spdlog/wiki/2.-Creating-loggers#accessing-loggers-using-spdlogget

#include <cassert>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_sinks.h"

int main(int, char* [])
{
    // Логгеры созданные вручную, т.е. прямым конструированием, автоматически не регистрируются
    // и небудут найдены вызовом get("...").
    
    auto sink = std::make_shared<spdlog::sinks::stdout_sink_mt>();
    auto my_logger= std::make_shared<spdlog::logger>("mylogger", sink);

    auto the_same_logger = spdlog::get("mylogger");
    assert(!the_same_logger);

    // Регистрация логгера:
    spdlog::register_logger(my_logger);

    the_same_logger = spdlog::get("mylogger");
    assert(the_same_logger);
}