#include <iostream>
#include <string>
#include <vector>

#include "virtual.h"
#include "override.h"
#include "define.h"

std::vector<std::string> g_types
{
    "bool",
    "float",
//    "double",
    "char const*",
//    "wchar_t const*",

//    "signed char",
//    "short int",
    "int",
//    "long int",
//    "long long int",

//    "std::int8_t",
//    "std::int16_t",
//    "std::int32_t",
//    "std::int64_t",
//    "std::uint8_t",
//    "std::uint16_t",
    "std::uint32_t",
//    "std::uint64_t",

//    "std::size_t",

    "std::string const&",
//    "std::wstring const&",

    "Vector3 const&",
    "Quaternion const&",
    "Guid const&",
};

void print(int sz, bool declare)
{
    std::string arg[sz];

    auto foo = [&]()
    {
        if (declare)
        {
            std::cout << "DECLARE_LOG_METHOD(SINGLE_ARG(std::string const& fmt";
            for (auto const& a : arg)
                std::cout << a;
            std::cout << "))" << std::endl;
        }
        else
        {
            std::cout << "DEFINE_LOG_METHOD(SINGLE_ARG(std::string const& fmt";
            for (auto const& a : arg)
                std::cout << a;
            std::cout << "), SINGLE_ARG(fmt";
            for (int i = 1; i <= sz; ++i)
                std::cout << ", arg" << i;
            std::cout << "))" << std::endl;
        }
    };

    for (int a = 0; a < g_types.size(); ++a)
    {
        arg[0] = ", " + g_types[a] + " arg1";
        if (sz > 1)
            for (int b = 0; b < g_types.size(); ++b)
            {
                arg[1] = ", " + g_types[b] + " arg2";
                if (sz > 2)
                    for (int c = 0; c < g_types.size(); ++c)
                    {
                        arg[2] = ", " + g_types[c] + " arg3";
                        if (sz > 3)
                            for (int d = 0; d < g_types.size(); ++d)
                            {
                                arg[3] = ", " + g_types[d] + " arg4";
                                if (sz > 4)
                                    for (int e = 0; e < g_types.size(); ++e)
                                    {
                                        arg[4] = ", " + g_types[e] + " arg5";
                                        if (sz > 5)
                                            {}
                                        else
                                            foo();
                                    }  // e
                                else
                                    foo();
                            }  // d
                        else
                            foo();
                    }  // c
                else
                    foo();
            }  // b
        else
            foo();
    }  // a
}

int main()
{
    int sz = 1;

    for (int i = 1; i <= sz; ++i)
        print(i, true);

    std::cout << std::endl;

    for (int i = 1; i <= sz; ++i)
        print(i, false);

    return 0;
}
