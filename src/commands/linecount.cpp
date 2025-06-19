#include "../headers/linecount.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::string LineCountCommand::name() const {
    return "linecount";
}

void LineCountCommand::execute(const std::string& args) {
    std::istringstream iss(args);
    std::string filePath;
    iss >> filePath;

    if (filePath.empty()) {
        std::cerr << "Returns the total lines of a text file.\n" << "Usage: linecount <file_path>\n";
        return;
    }

    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file '" << filePath << "'\n";
        std::cout << "You can use the 'cwd' command to see your current working directory.\n";
        return;
    }

    size_t lineCount = 0;
    std::string line;
    while (std::getline(file, line)) {
        ++lineCount;
    }

    std::cout << "File '" << filePath << "' has " << lineCount << " lines.\n";
}
