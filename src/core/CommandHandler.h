#pragma once

#include <string>
#include <map>
#include <memory>
#include <chrono>
#include "ICommand.h"

class CommandHandler {
public:
    CommandHandler();
    void run();

    std::chrono::time_point<std::chrono::steady_clock> getSessionStartTime() const;

private:
    std::chrono::time_point<std::chrono::steady_clock> sessionStart;
    std::map<std::string, std::unique_ptr<ICommand>> commands;
    bool running;

    void registerCommands();
};