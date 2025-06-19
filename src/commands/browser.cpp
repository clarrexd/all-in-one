#include "../headers/browser.h"
#include <cstdlib>   // for std::system
#include <iostream>

// helper to check if a command exists in PATH
bool commandExists(const std::string& cmd) {
    std::string checkCmd = "command -v " + cmd + " > /dev/null 2>&1";
    return std::system(checkCmd.c_str()) == 0;
}

std::string BrowserCommand::name() const {
    return "browser";
}

void BrowserCommand::execute(const std::string& args) {
    (void)args;
    const char* url = "https://www.google.com";
    std::string cmd;

#if defined(_WIN32) || defined(_WIN64)
    cmd = "start " + std::string(url);
#elif defined(__APPLE__)
    cmd = "open " + std::string(url);
#elif defined(__linux__)
    // Check if xdg-open exists
    if (!commandExists("xdg-open")) {
        std::cerr << "Error: 'xdg-open' is not installed. Please install 'xdg-utils' package.\n";
        return;
    }
    cmd = "xdg-open " + std::string(url);
#else
    std::cerr << "Unsupported OS for opening browser.\n";
    return;
#endif

    int result = std::system(cmd.c_str());

    if (result == 0) {
        std::cout << "Browser opened successfully.\n";
    } else {
        std::cout << "Failed to open browser.\n";
    }
}