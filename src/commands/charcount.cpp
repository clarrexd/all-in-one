#include "../headers/charcount.h"
#include <iostream>
#include <fstream>
#include <cctype>  // for std::isspace

void CharCountCommand::execute(const std::string& args) {
    if (args.empty()) {
        std::cout << "Error: No file path provided.\nUsage: charcount <filepath>\n";
        return;
    }

    std::ifstream file(args);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file '" << args << "'.\n";
        std::cout << "Use 'cwd' to check the current working directory.\n";
        return;
    }

    size_t charCount = 0;
    char c;

    while (file.get(c)) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            ++charCount;
        }
    }

    std::cout << "Number of characters (excluding whitespaces) in file '" << args << "': " << charCount << "\n";
}