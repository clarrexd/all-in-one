#include "../headers/exit.h"
#include <iostream>

ExitCommand::ExitCommand(std::function<void()> callback)
    : onExit(std::move(callback)) {}

std::string ExitCommand::name() const {
    return "exit";
}

void ExitCommand::execute(const std::string& args) {
    (void)args;
    std::cout << "Exiting session...\n";
    onExit();  // Notify the handler to stop running
}