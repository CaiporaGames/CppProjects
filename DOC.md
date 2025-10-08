# USE POWERSHELL FOR THESE COMMANDS

# How to run cmakelist any time it give problem:
1. Delete the build folder.
2. Enter the build folder and run:cmake ..

# How to generate the exe:
1. Create a build folder if does not exist.
2. cd to build folder and enter: cmake .. -G "Ninja"
3. Enter:ninja

# How to see the logs:
1. From inside the build folder run: ./SystemMonitor or 
    ./SystemMonitor --interval 10  # this is if the main receives arguments.
    ./SystemMonitor --interval 3 --output mylog.txt # when you need to log to another file name.
    ./SystemMonitor --interval 3 --duration 15 --output testlog.txt # when you want to control log time
    ./SystemMonitor --interval 3 --duration 15 --verbose # when we want to log the txt data in the console.
    ./SystemMonitor --interval 1 --duration 10 --verbose # for simulationg safe thread.
    ./SystemMonitor --interval 2 --duration 10 --threads 2 --cpu --mem --verbose # conditionaly logs parts of the data
2. then run:cat system_log.txt