#include "headers/CommandHandler.h"
#include "headers/responsetime.h"
#include "headers/browser.h"
#include "headers/linecount.h"
#include "headers/cwd.h"
#include "headers/charcount.h"
#include "../src/commands/time.cpp"
#include "../src/commands/exit.cpp"

#include <iostream>
#include <sstream>  // For std::istringstream

CommandHandler::CommandHandler() : running(true) {
    registerCommands();
}

void CommandHandler::registerCommands() {
    commands["time"] = std::make_unique<TimeCommand>();
    commands["responsetime"] = std::make_unique<ResponseTimeCommand>();
    commands["browser"] = std::make_unique<BrowserCommand>();
    commands["linecount"] = std::make_unique<LineCountCommand>();
    commands["cwd"] = std::make_unique<CwdCommand>();
    commands["charcount"] = std::make_unique<CharCountCommand>();
    commands["exit"] = std::make_unique<ExitCommand>([this]() { running = false; });
}

void CommandHandler::run() {
    std::string input;

    std::cout << "Welcome to your All-In-One application. Type a command or 'exit' to quit.\n";

    while (running) {
        std::cout << "> ";
        std::getline(std::cin, input);

        // Parse input into command and args
        std::istringstream iss(input);
        std::string commandName;
        iss >> commandName;

        // Get the rest of the line as args (trim leading spaces)
        std::string args;
        std::getline(iss, args);
        size_t firstNonSpace = args.find_first_not_of(' ');
        if (firstNonSpace != std::string::npos) {
            args = args.substr(firstNonSpace);
        } else {
            args.clear();
        }

        // Look up command by commandName only
        auto it = commands.find(commandName);
        if (it != commands.end()) {
            it->second->execute(args);
        } else {
            std::cout << "Unknown command: " << commandName << "\nType 'help' for more options.\n";
        }
    }

    std::cout << "Session ended.\n";
}
