//
// Created by kyle on 2026-03-16.
//

#include "../include/Parser.h"

#include <iostream>
#include <fstream>

#include "../include/StringUtils.h"

Parser::Parser(const std::string& filePath) {
    // Open assembly program
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Unable to open assembly file: " << filePath << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(file, line)) {
        Trim(line);

        if (!StartsWith(line, '/') && !line.empty()) {
            if (const size_t pos = line.find('/'); pos != -1) {
                line.erase(pos, line.length() - 1);
            }
            lines.push_back(line);
        }
    }

    if (lines.empty()) {
        std::cerr << "Assembly file provided contains no instructions. Please provide a valid file." << std::endl;
        exit(EXIT_FAILURE);
    }
}

bool Parser::hasMoreCommands() const {
    return currentCommandNumber > lines.size() - 1;
}

void Parser::advance() {
    currentCommand = lines[currentCommandNumber];
    currentCommandNumber++; // Starts @ 0 but first command/line in file should be 1
}

CommandType Parser::commandType() {
    throw std::runtime_error("Not implemented");
}

std::string Parser::symbol() {
    throw std::runtime_error("Not implemented");
}

std::string Parser::dest() {
    throw std::runtime_error("Not implemented");
}

std::string Parser::comp() {
    throw std::runtime_error("Not implemented");
}

std::string Parser::jump() {
    throw std::runtime_error("Not implemented");
}