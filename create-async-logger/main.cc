// https://github.com/gabime/spdlog/wiki/2.-Creating-loggers#creating-asynchronous-loggers

#include "spdlog/async.h"
#include "spdlog/sinks/basic_file_sink.h" // support for basic file logging

// Для асинхронного логирования uses использует shared global thread pool с dedicated message queue.
// Создается фиксированное число pre-allocated slots в message queue (~256 bytes per slot in 64 bits),
// но можно модифицировать используя spdlog::init_thread_pool(queue_size, backing_threads_count).
// При попытке логировать сообщение при полной очереди, caller будет заблокирован (default behavior)
// пока слоты не станут доступны (default),
// или если логгер был сконструирован с async_overflow_policy==overrun_oldest, 
// то самое старое сообщение в очереди будет немедленно заменено новым

void async_example()
{
    // default thread pool settings can be modified *before* creating the async logger:
    // spdlog::init_thread_pool(8192, 1); // queue with 8k items and 1 backing thread.
    auto async_file = spdlog::basic_logger_mt<spdlog::async_factory>("async_file_logger", "logs/async_log.txt");
    // alternatively:
    // auto async_file = spdlog::create_async<spdlog::sinks::basic_file_sink_mt>("async_file_logger", "logs/async_log.txt");
}

int main(int, char* [])
{
    async_example();
}