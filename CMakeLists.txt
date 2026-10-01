cmake_minimum_required(VERSION 3.16)

project(sockets LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE include/asio)
target_compile_definitions(${PROJECT_NAME} PRIVATE ASIO_STANDALONE)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)