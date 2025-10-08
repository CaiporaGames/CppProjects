#include "Logger.hpp"
#include "Monitor.hpp"
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    int interval = 5;
    int duration = -1; // -1 means run forever
    std::string outputFile = "system_log.txt";
    bool verbose = false;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--interval" && i + 1 < argc) {
            interval = std::atoi(argv[i + 1]);
        }
        if (arg == "--output" && i + 1 < argc) {
            outputFile = argv[i + 1];
        }
        if (arg == "--duration" && i + 1 < argc) {
            duration = std::atoi(argv[i + 1]);
        }
        if (arg == "--verbose") {
            verbose = true;
        }
    }

    Logger::setOutputFile(outputFile);
    Logger::setVerbose(verbose);

    std::cout << "Logging every " << interval << " seconds to " << outputFile;
    if (duration > 0) std::cout << " for " << duration << " seconds";
    std::cout << "...\n";

    std::thread monitorThread([interval, duration]() {
        auto start = std::chrono::steady_clock::now();
        while (true) {
            Logger::log(getCPUUsage());
            Logger::log(getMemoryUsage());
            Logger::log(getUptime());

            std::this_thread::sleep_for(std::chrono::seconds(interval));

            if (duration > 0) {
                auto now = std::chrono::steady_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
                if (elapsed >= duration) break;
            }
        }
    });

    monitorThread.join();
    return 0;
}