cmake_minimum_required(VERSION 3.10)
project(SystemMonitor)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(SystemMonitor
    main.cpp
    src/Logger.cpp
    src/Monitor.cpp
)