#include "Logger.hpp"
#include "Monitor.hpp"
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    int interval = 5; // default seconds
    std::string outputFile = "system_log.txt";

    // Parse --interval argument
    for (int i = 1; i < argc; ++i) 
    {
        std::string arg = argv[i];
        if (arg == "--interval" && i + 1 < argc) 
        {
            interval = std::atoi(argv[i + 1]);
        }
        if(arg == "--output" && i+1 < argc)
        {
            outputFile = argv[i+1];
        }
    }
    Logger::setOutputFile(outputFile);
    std::cout << "Logging every " << interval << " seconds to 0 "<< outputFile << " ...\n";

    std::thread monitorThread([interval]() 
    {
        while (true) 
        {
            std::cout << "Logging system info...\n"; // Add this line
            Logger::log(getCPUUsage());
            Logger::log(getMemoryUsage());
            Logger::log(getUptime());
            std::this_thread::sleep_for(std::chrono::seconds(interval));
        }
    });

    monitorThread.join();
    return 0;
}