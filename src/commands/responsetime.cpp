#include "../headers/responsetime.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>

std::string ResponseTimeCommand::name() const {
    return "responsetime";
}

void ResponseTimeCommand::execute(const std::string& args) {
    (void)args;
    std::vector<long long> responseTimes;

    std::random_device rd;
    std::mt19937 gen(rd());
    //std::uniform_int_distribution<> dist(50, 250);

    for (int i = 0; i < 5; ++i) {
        auto start = std::chrono::high_resolution_clock::now();

        //this line is to simulate some latency
        //std::this_thread::sleep_for(std::chrono::milliseconds(dist(gen)));

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        responseTimes.push_back(duration);
    }

    std::cout << "\nSimulated Command Response Times:\n";
    for (size_t i = 0; i < responseTimes.size(); ++i) {
        std::cout << "Command " << (i + 1) << ": " << responseTimes[i] << " ms\n";
    }
}