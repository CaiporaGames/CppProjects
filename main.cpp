#include "Logger.hpp"
#include "Monitor.hpp"
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <vector> 

int main(int argc, char* argv[]) {
    int interval = 5;
    int duration = -1;
    int threads = 1;
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
        if(arg == "--threads" && i+1 < argc)
        {
            threads = std::atoi(argv[i+1]);
        }
    }

    Logger::setOutputFile(outputFile);
    Logger::setVerbose(verbose);

    std::vector<std::thread> threadPool;

    for (int t = 0; t < threads; ++t) {
        threadPool.emplace_back([interval, duration, t]() {
            auto start = std::chrono::steady_clock::now();
            while (true) {
                Logger::log("Thread " + std::to_string(t) + " - " + getCPUUsage());
                Logger::log("Thread " + std::to_string(t) + " - " + getMemoryUsage());
                Logger::log("Thread " + std::to_string(t) + " - " + getUptime());

                std::this_thread::sleep_for(std::chrono::seconds(interval));

                if (duration > 0) {
                    auto now = std::chrono::steady_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
                    if (elapsed >= duration) break;
                }
            }
        });
    }

    // Wait for all threads to finish
    for (auto& t : threadPool) {
        t.join();
    }
    return 0;
}