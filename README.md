spdlog - header only библиотека.
Предоставляет python like formatting API используя идущий в комплекте [fmt](https://github.com/fmtlib/fmt) lib (см. [reference](https://fmt.dev/latest/syntax.html)).
spdlog использует подход "include what you need" - в коде следует подключать только фактически используемые фичи.

# Thread Safety

Для создания thread safe логгеров используются ```_mt``` фабричные функции:

- ```auto logger = spdlog::basic_logger_mt(...);```

Для создания single threaded логгеров используются ```_st``` фабричные функции:

- ```auto logger = spdlog::basic_logger_st(...);```

Каждый логгер содержит vector из одного или нескольких ```std::shared_ptr<spdlog::sink>```.
На каждом log call (если log level правильный) logger на каждом из них вызывает функцию ```sink(log_msg)```.
Суффиксы sink'ов говорят об их thread safety:

- ```_mt``` (multi threaded) - могут использоваться одновременно из множества потоков.
   - ```daily_file_sink_mt```
- ```_st``` (single threaded) - быстрее потому что нет блокировок.
   - ```daily_file_sink_st```

Следующие функции не могут быть вызваны concurrently из множества потоков на одном и том же logger объекте:

- ```set_error_handler(log_err_handler);```
- ```logger::sinks()``` - возвращает reference на non thread safe vector, поэтому нельзя его модифицировать concurrently
   - например, ```logger->sinks().push_back(new_sink);```

Эти ограничения применимы ко всем видам логгеров (```_mt``` или ```_st```).

# Sinks

Начиная с версии 1.5.0, spdlog при необходимости создает папки содержащие log файлы. 
Ранее папки нужно было создавать вручную.

| ```#include "spdlog/sinks/.h"``` | ```spdlog::sinks::```  | ```spdlog::``` |
| - | - | - |
| ```ansicolor_sink``` | ```ansicolor_stdout_sink_st``` | |
| ```ansicolor_sink``` | ```ansicolor_stdout_sink_mt``` | |
| ```ansicolor_sink``` | ```ansicolor_stderr_sink_st``` | |
| ```ansicolor_sink``` | ```ansicolor_stderr_sink_mt``` | |
| ```stdout_color_sinks``` | ```stdout_color_sink_st``` | ```stdout_color_st``` |
| ```stdout_color_sinks``` | ```stdout_color_sink_mt``` | ```stdout_color_mt``` |
| ```stdout_color_sinks``` | ```stderr_color_sink_st``` | ```stderr_color_st``` |
| ```stdout_color_sinks``` | ```stderr_color_sink_mt``` | ```stderr_color_mt``` |
| ```stdout_sinks``` | ```stdout_sink_st``` | ```stdout_logger_st``` |
| ```stdout_sinks``` | ```stdout_sink_mt``` | ```stdout_logger_mt``` |
| ```stdout_sinks``` | ```stderr_sink_st``` | ```stderr_logger_st``` |
| ```stdout_sinks``` | ```stderr_sink_mt``` | ```stderr_logger_mt``` |
| ```basic_file_sink``` | ```basic_file_sink_st``` | ```basic_logger_st``` |
| ```basic_file_sink``` | ```basic_file_sink_mt``` | ```basic_logger_mt``` |
| ```rotating_file_sink``` | ```rotating_file_sink_st``` | ```rotating_logger_st``` |
| ```rotating_file_sink``` | ```rotating_file_sink_mt``` | ```rotating_logger_mt``` |
| ```daily_file_sink``` | ```daily_file_sink_st``` | ```daily_logger_st``` |
| ```daily_file_sink``` | ```daily_file_sink_mt``` | ```daily_logger_mt``` |
| ```daily_file_sink``` | ```daily_file_format_sink_st``` | ```daily_logger_format_st``` |
| ```daily_file_sink``` | ```daily_file_format_sink_mt``` | ```daily_logger_format_mt``` |
| ```hourly_file_sink``` | ```hourly_file_sink_st``` | ```hourly_logger_st``` |
| ```hourly_file_sink``` | ```hourly_file_sink_mt``` | ```hourly_logger_mt``` |
| ```ostream_sink``` | ```ostream_sink_st``` | |
| ```ostream_sink``` | ```ostream_sink_mt``` | |
| ```dist_sink``` | ```dist_sink_st``` | |
| ```dist_sink``` | ```dist_sink_mt``` | |
| ```dup_filter_sink``` | ```dup_filter_sink_st``` | |
| ```dup_filter_sink``` | ```dup_filter_sink_mt``` | |
| ```ringbuffer_sink``` | ```ringbuffer_sink_st``` | |
| ```ringbuffer_sink``` | ```ringbuffer_sink_mt``` | |
| ```syslog_sink``` | ```syslog_sink_st``` | ```syslog_logger_st``` |
| ```syslog_sink``` | ```syslog_sink_mt``` | ```syslog_logger_mt``` |
| ```tcp_sink``` | ```tcp_sink_st``` | |
| ```tcp_sink``` | ```tcp_sink_mt``` | |
| ```udp_sink``` | ```udp_sink_st``` | |
| ```udp_sink``` | ```udp_sink_mt``` | ```udp_logger_mt``` |
| ```null_sink``` | ```null_sink_st``` | ```null_logger_st``` |
| ```null_sink``` | ```null_sink_mt``` | ```null_logger_mt``` |

# Usage samples

- 1 Быстрый старт
   - [Hello, World!](hello)
   - [Подход "include what you need"](include-what-you-need)
   - [Асинхронный логгер использующий фабричный метод](asynchronous-logger-using-factory-method)
   - [Создание асинхронного логгера и изменение настроек пула потоков](async-logger-and-thread-pool-settings)
   - [**Несколько логгеров совместно использующих один файл (sink)**](multiple-loggers-sharing-same-sink)
   - [**Логгер со множеством sink'ов**](logger-with-multiple-sinks)
   - [Макросы логирования](logging-macros)
   - [Логирование пользовательских объектов](log-user-defined-objects)
   - [Логирование пользовательских объектов с продвинутым форматированием](log-user-defined-objects-advanced-formatting)
- 2 Создание логгеров
   - [Создание логгера с помощью фабричной функции](create-logger-using-factory-fn)
   - [**Доступ к логгеру через ```spdlog::get("...")```**](spdlog-get)
   - [Логгеры созданные вручную, т.е. прямым конструированием, автоматически не регистрируются](manually-created-logger)
   - [Создание rotating файлового логгера](create-rotating-file-logger)
   - [Создание асинхронного логгера](create-async-logger)
   - [Создание логгера вручную](create-logger-manually)
- [Исследование API](aio)
