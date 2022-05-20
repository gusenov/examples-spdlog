#include <iostream>

#include "spdlog/spdlog.h"

#include "spdlog/sinks/sink.h"  // интерфейс приёмника.

        // wincolor_sink или ansicolor_sink подключаются через registry.h,
        // который в свою очередь подключается через главный spdlog.h.
#ifdef _WIN32
        #include "spdlog/sinks/wincolor_sink.h"
#else
        #include "spdlog/sinks/ansicolor_sink.h"
#endif
        #include "spdlog/sinks/stdout_color_sinks.h"  // псевдонимы за которыми может быть wincolor_sink или ansicolor_sink

        #include "spdlog/sinks/stdout_sinks.h"

        #include "spdlog/sinks/base_sink.h"

                #include "spdlog/sinks/basic_file_sink.h"
                #include "spdlog/sinks/rotating_file_sink.h"
                #include "spdlog/sinks/daily_file_sink.h"
                #include "spdlog/sinks/hourly_file_sink.h"

                #include "spdlog/sinks/ostream_sink.h"

                #include "spdlog/sinks/dist_sink.h"
                        #include "spdlog/sinks/dup_filter_sink.h"

                #include "spdlog/sinks/ringbuffer_sink.h"

                #include "spdlog/sinks/syslog_sink.h"

                #include "spdlog/sinks/tcp_sink.h"
                #include "spdlog/sinks/udp_sink.h"

                #include "spdlog/sinks/null_sink.h"

//#include "spdlog/sinks/android_sink.h"
#include "spdlog/sinks/msvc_sink.h"
//#include "spdlog/sinks/qt_sinks.h"
//#include "spdlog/sinks/systemd_sink.h"
//#include "spdlog/sinks/win_eventlog_sink.h"
//#include "spdlog/sinks/mongo_sink.h"

void sinks()
{
    {  // ansicolor_sink
        spdlog::color_mode mode = spdlog::color_mode::automatic;

        std::make_shared<spdlog::sinks::ansicolor_stdout_sink_st>(mode);
        std::make_shared<spdlog::sinks::ansicolor_stdout_sink_mt>(mode);

        std::make_shared<spdlog::sinks::ansicolor_stderr_sink_st>(mode);
        std::make_shared<spdlog::sinks::ansicolor_stderr_sink_mt>(mode);
    }

    {  // stdout_color_sinks

        // std???_color_sink_?t это псевдонимы за которыми может быть
        //  ansicolor_std???_sink_?t или
        //   wincolor_std???_sink_?t.

        std::make_shared<spdlog::sinks::stdout_color_sink_st>();
        std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

        std::make_shared<spdlog::sinks::stderr_color_sink_st>();
        std::make_shared<spdlog::sinks::stderr_color_sink_mt>();
    }

    {  // stdout_sinks
        std::make_shared<spdlog::sinks::stdout_sink_st>();
        std::make_shared<spdlog::sinks::stdout_sink_mt>();

        std::make_shared<spdlog::sinks::stderr_sink_st>();
        std::make_shared<spdlog::sinks::stderr_sink_mt>();
    }

    {  // basic_file_sink
        spdlog::filename_t const filename;
        bool truncate = false;
        spdlog::file_event_handlers const event_handlers = {};

        std::make_shared<spdlog::sinks::basic_file_sink_st>(filename, truncate, event_handlers);
        std::make_shared<spdlog::sinks::basic_file_sink_mt>(filename, truncate, event_handlers);
    }

    {  // rotating_file_sink
        spdlog::filename_t base_filename;
        std::size_t max_size;
        std::size_t max_files;
        bool rotate_on_open = false;
        spdlog::file_event_handlers const event_handlers = {};

        std::make_shared<spdlog::sinks::rotating_file_sink_st>(base_filename, max_size, max_files, rotate_on_open, event_handlers);
        std::make_shared<spdlog::sinks::rotating_file_sink_mt>(base_filename, max_size, max_files, rotate_on_open, event_handlers);
    }

    {  // daily_file_sink
        spdlog::filename_t base_filename;
        int rotation_hour;
        int rotation_minute;
        bool truncate = false;
        uint16_t max_files = 0;
        spdlog::file_event_handlers const event_handlers = {};

        std::make_shared<spdlog::sinks::daily_file_sink_st>(base_filename, rotation_hour, rotation_minute, truncate, max_files, event_handlers);
        std::make_shared<spdlog::sinks::daily_file_sink_mt>(base_filename, rotation_hour, rotation_minute, truncate, max_files, event_handlers);

        std::make_shared<spdlog::sinks::daily_file_format_sink_st>(base_filename, rotation_hour, rotation_minute, truncate, max_files, event_handlers);
        std::make_shared<spdlog::sinks::daily_file_format_sink_mt>(base_filename, rotation_hour, rotation_minute, truncate, max_files, event_handlers);
    }

    {  // hourly_file_sink
        spdlog::filename_t base_filename;
        bool truncate = false;
        uint16_t max_files = 0;
        spdlog::file_event_handlers const event_handlers = {};

        std::make_shared<spdlog::sinks::hourly_file_sink_st>(base_filename, truncate, max_files, event_handlers);
        std::make_shared<spdlog::sinks::hourly_file_sink_mt>(base_filename, truncate, max_files, event_handlers);
    }

    {  // ostream_sink
        std::ostream& os = std::cout;
        bool force_flush = false;

        std::make_shared<spdlog::sinks::ostream_sink_st>(os, force_flush);
        std::make_shared<spdlog::sinks::ostream_sink_mt>(os, force_flush);
    }

    {  // dist_sink
        std::vector<std::shared_ptr<spdlog::sinks::sink>> sinks;

        std::make_shared<spdlog::sinks::dist_sink_st>(sinks);
        std::make_shared<spdlog::sinks::dist_sink_mt>(sinks);
    }

    {  // dup_filter_sink
        std::make_shared<spdlog::sinks::dup_filter_sink_st>(std::chrono::seconds(5));
        std::make_shared<spdlog::sinks::dup_filter_sink_mt>(std::chrono::seconds(5));
    }

    {  // ringbuffer_sink
        size_t n_items;

        std::make_shared<spdlog::sinks::ringbuffer_sink_st>(n_items);
        std::make_shared<spdlog::sinks::ringbuffer_sink_mt>(n_items);
    }

    {  // syslog_sink
        std::string ident;
        int syslog_option;
        int syslog_facility;
        bool enable_formatting;

        std::make_shared<spdlog::sinks::syslog_sink_st>(ident, syslog_option, syslog_facility, enable_formatting);
        std::make_shared<spdlog::sinks::syslog_sink_mt>(ident, syslog_option, syslog_facility, enable_formatting);
    }

    {  // tcp_sink
        std::string host;
        int port;
        spdlog::sinks::tcp_sink_config sink_config(host, port);

        std::make_shared<spdlog::sinks::tcp_sink_st>(sink_config);
        std::make_shared<spdlog::sinks::tcp_sink_mt>(sink_config);
    }

    {  // udp_sink
        std::string host;
        uint16_t port;
        spdlog::sinks::udp_sink_config udp_sink_config(host, port);

        std::make_shared<spdlog::sinks::udp_sink_st>(udp_sink_config);
        std::make_shared<spdlog::sinks::udp_sink_mt>(udp_sink_config);
    }

    {  // null_sink
        auto st = std::make_shared<spdlog::sinks::null_sink_st>();
        auto mt = std::make_shared<spdlog::sinks::null_sink_mt>();
    }
}

void loggers()
{
    {  // stdout_color_sinks
        std::string const logger_name;

        spdlog::stdout_color_st(logger_name);
        spdlog::stdout_color_mt(logger_name);

        spdlog::stderr_color_st(logger_name);
        spdlog::stderr_color_mt(logger_name);
    }

    {  // stdout_sinks
        std::string const logger_name;

        spdlog::stdout_logger_st(logger_name);
        spdlog::stdout_logger_mt(logger_name);

        spdlog::stderr_logger_st(logger_name);
        spdlog::stderr_logger_mt(logger_name);
    }

    {  // basic_file_sink
        std::string const logger_name;
        spdlog::filename_t const filename;
        bool truncate = false;
        spdlog::file_event_handlers const event_handlers = {};

        spdlog::basic_logger_st(logger_name, filename, truncate, event_handlers);
        spdlog::basic_logger_mt(logger_name, filename, truncate, event_handlers);
    }

    {  // rotating_file_sink
        std::string const logger_name;
        spdlog::filename_t const filename;
        size_t max_file_size;
        size_t max_files;
        bool rotate_on_open = false;
        spdlog::file_event_handlers const event_handlers = {};

        spdlog::rotating_logger_st(logger_name, filename, max_file_size, max_files, rotate_on_open, event_handlers);
        spdlog::rotating_logger_mt(logger_name, filename, max_file_size, max_files, rotate_on_open, event_handlers);
    }

    {  // daily_file_sink
        std::string const logger_name;
        const spdlog::filename_t filename;
        int hour = 0;
        int minute = 0;
        bool truncate = false;
        uint16_t max_files = 0;
        const spdlog::file_event_handlers &event_handlers = {};

        spdlog::daily_logger_st(logger_name, filename, hour, minute, truncate, max_files, event_handlers);
        spdlog::daily_logger_mt(logger_name, filename, hour, minute, truncate, max_files, event_handlers);

        spdlog::daily_logger_format_st(logger_name, filename, hour, minute, truncate, max_files, event_handlers);
        spdlog::daily_logger_format_mt(logger_name, filename, hour, minute, truncate, max_files, event_handlers);
    }

    {  // hourly_file_sink
        std::string const logger_name;
        const spdlog::filename_t filename;
        bool truncate = false;
        uint16_t max_files = 0;
        const spdlog::file_event_handlers &event_handlers = {};

        spdlog::hourly_logger_st(logger_name, filename, truncate, max_files, event_handlers);
        spdlog::hourly_logger_mt(logger_name, filename, truncate, max_files, event_handlers);
    }

    {  // syslog_sink
        std::string const logger_name;
        std::string const syslog_ident = "";
        int syslog_option = 0;
        int syslog_facility = LOG_USER;
        bool enable_formatting = false;

        spdlog::syslog_logger_st(logger_name, syslog_ident, syslog_option, syslog_facility, enable_formatting);
        spdlog::syslog_logger_mt(logger_name, syslog_ident, syslog_option, syslog_facility, enable_formatting);
    }

    {  // udp_sink
        std::string const logger_name;
        std::string host;
        uint16_t port;
        spdlog::sinks::udp_sink_config skin_config(host, port);

        spdlog::udp_logger_mt(logger_name, skin_config);
    }

    {  // null_sink
        std::string const logger_name;

        auto st = spdlog::null_logger_st(logger_name);
        auto mt = spdlog::null_logger_mt(logger_name);
    }
}

template<typename T>
void messages(T const& msg)
{
    spdlog::trace(msg);
    spdlog::log(spdlog::level::level_enum::trace, msg);

    spdlog::debug(msg);
    spdlog::log(spdlog::level::level_enum::debug, msg);

    spdlog::info(msg);
    spdlog::log(spdlog::level::level_enum::info, msg);

    spdlog::warn(msg);
    spdlog::log(spdlog::level::level_enum::warn, msg);

    spdlog::error(msg);
    spdlog::log(spdlog::level::level_enum::err, msg);

    spdlog::critical(msg);
    spdlog::log(spdlog::level::level_enum::critical, msg);
}

int main()
{
    return 0;
}
