#pragma once

#include <string>
#include <map>
#include <memory>
#include "ICommand.h"

class CommandHandler {
public:
    CommandHandler();
    void run();

private:
    std::map<std::string, std::unique_ptr<ICommand>> commands;
    bool running;

    void registerCommands();
};