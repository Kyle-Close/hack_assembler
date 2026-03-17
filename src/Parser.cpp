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
}

bool Parser::hasMoreCommands() {
    throw std::runtime_error("Not implemented");
}

void Parser::advance() {
    throw std::runtime_error("Not implemented");
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