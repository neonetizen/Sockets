cmake_minimum_required(VERSION 3.16)

project(sockets LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE include)
target_compile_definitions(${PROJECT_NAME} PRIVATE ASIO_STANDALONE)
