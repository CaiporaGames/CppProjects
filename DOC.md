# USE POWERSHELL FOR THESE COMMANDS

# 🧼 Clean Build (when things break)
rm -r build
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:/Users/timot/vcpkg/scripts/buildsystems/vcpkg.cmake -G "Ninja"
ninja

# ⚙️ Standard Build
mkdir -p build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:/Users/timot/vcpkg/scripts/buildsystems/vcpkg.cmake -G "Ninja"
ninja

# How to see the logs:
1. From inside the build folder run: 
    ./SystemMonitor or 
    ./SystemMonitor --interval 10  # this is if the main receives arguments.
    ./SystemMonitor --interval 3 --output mylog.txt # when you need to log to another file name.
    ./SystemMonitor --interval 3 --duration 15 --output testlog.txt # when you want to control log time
    ./SystemMonitor --interval 3 --duration 15 --verbose # when we want to log the txt data in the console.
    ./SystemMonitor --interval 1 --duration 10 --verbose # for simulationg safe thread.
    ./SystemMonitor --interval 2 --duration 10 --threads 2 --cpu --mem --verbose # conditionaly logs parts of the data
2. then run:cat system_log.txt