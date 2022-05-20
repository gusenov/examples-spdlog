#include <cassert>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int main()
{
    auto sink1 = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    sink1->set_level(spdlog::level::info);

    auto sink2 = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    sink2->set_level(spdlog::level::warn);
    
    std::vector<spdlog::sink_ptr> sinks {
        sink1, sink2
    };
    
    auto logger = std::make_shared<spdlog::logger>("my_logger", std::begin(sinks), std::end(sinks));
    assert(2 == logger->sinks().size());
    logger->set_level(spdlog::level::info);
    
    logger->info("info");
    logger->warn("warn");
    // [2022-01-28 10:40:39.514] [my_logger] [info] info
    // [2022-01-28 10:40:39.515] [my_logger] [warning] warn
    // [2022-01-28 10:40:39.515] [my_logger] [warning] warn
}
