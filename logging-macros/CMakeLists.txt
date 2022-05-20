cmake_minimum_required(VERSION 3.19)
project(LoggingMacros)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cc)

target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/../spdlog/include")
