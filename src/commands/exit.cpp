#include "../headers/ICommand.h"
#include <iostream>
#include <functional>

class ExitCommand : public ICommand {
public:
    ExitCommand(std::function<void()> callback) : onExit(callback) {}

    std::string name() const override { return "exit"; }

    void execute(const std::string& args) override {
        (void)args;
        std::cout << "Exiting session...\n";
        onExit();  // notify the handler to stop running
    }

private:
    std::function<void()> onExit;
};