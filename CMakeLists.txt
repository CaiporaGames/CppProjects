cmake_minimum_required(VERSION 3.10)
project(SystemMonitor)

set(CMAKE_CXX_STANDARD 17)

# Let CMake know to use vcpkg's toolchain (set this when configuring)
# cmake -DCMAKE_TOOLCHAIN_FILE=C:/Users/timot/vcpkg/scripts/buildsystems/vcpkg.cmake ..

# Optional: explicitly find and link nlohmann_json
find_package(nlohmann_json CONFIG REQUIRED)

include_directories(include)

add_executable(SystemMonitor
    main.cpp
    src/Logger.cpp
    src/Monitor.cpp
)

# Link the JSON library (header-only, but this ensures future compatibility)
target_link_libraries(SystemMonitor PRIVATE nlohmann_json::nlohmann_json)