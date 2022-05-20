// https://github.com/gabime/spdlog/wiki/2.-Creating-loggers#accessing-loggers-using-spdlogget

#include <cassert>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

class MyClass
{
private:

   // spdlog::get может замедлить код, потому что она лочит mutex, использовать ее нужно осторожно.
   // Лучше сохранить возвращаемый shared_ptr<spdlog::logger> и использовать его напрямую хотя бы в hot code paths.
   // Хороший подход private member типа shared_ptr<spdlog::logger>, которому делается set в конструкторе.
   std::shared_ptr<spdlog::logger> _logger;
   
public:
   MyClass()
   {
     // Логгер можно получить откуда угодно используя функцию spdlog::get("logger_name"), которая возвращает shared pointer.

     //set _logger to some existing logger
     _logger = spdlog::get("some_logger");
     //or create directly
     //_logger = spdlog::rotating_file_logger_mt("my_logger", ...);
     
     assert(_logger);
   }
};

int main(int, char* [])
{
    // Создать и вернуть shared_ptr на multithreaded console logger.
    auto console = spdlog::stdout_color_mt("some_logger");
    // 1) Создает console logger.
    // 2) Регистрирует его в spdlog's global registry с "some_unique_name" в качестве id.
    // 3) Возвращает его как shared_ptr.
    
    MyClass myObject;
}