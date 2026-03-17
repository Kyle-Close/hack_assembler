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

CommandType Parser::commandType() const {
    if (StartsWith(currentCommand, '@')) {
        return A_COMMAND;
    } else if (Contains(currentCommand, '=') || Contains(currentCommand, ';')) {
        return C_COMMAND;
    } else if (StartsWith(currentCommand, '(')) {
        return L_COMMAND;
    } else {
        std::cerr << "Command not valid: " << currentCommand << std::endl;
        exit(EXIT_FAILURE);
    }
}

std::string Parser::symbol() const {
    if (commandType() == A_COMMAND) {
        return currentCommand.substr(1, currentCommand.length() - 1);
    } else if (commandType() == L_COMMAND) {
        return currentCommand.substr(1, currentCommand.length() - 2);
    } else {
        std::cerr << "Cannot get symbol of C type commands." << std::endl;
        exit(EXIT_FAILURE);
    }
}

std::string Parser::dest() const{
    if (commandType() != C_COMMAND) {
        std::cerr << "Can only get dest of C type commands. Passed in " << commandType() << std::endl;
        exit(EXIT_FAILURE);
    }

    const size_t index = currentCommand.find('=');

    if (index == -1) {
        return "";
    }

    return currentCommand.substr(0, index - 1);
}

std::string Parser::comp() const{
    if (commandType() != C_COMMAND) {
        std::cerr << "Can only get dest of C type commands. Passed in " << commandType() << std::endl;
        exit(EXIT_FAILURE);
    }

    const bool containsDest = Contains(currentCommand, '=');
    const bool containsJump = Contains(currentCommand, ';');

    size_t startIndex = 0;
    size_t endIndex = currentCommand.length() - 1;

    if (containsDest) {
        startIndex = currentCommand.find('=');
    }
    if (containsJump) {
        endIndex = currentCommand.find(';') - 1;
    }

    return currentCommand.substr(startIndex, endIndex - startIndex);
}

std::string Parser::jump() const{
    if (commandType() != C_COMMAND) {
        std::cerr << "Can only get dest of C type commands. Passed in " << commandType() << std::endl;
        exit(EXIT_FAILURE);
    }

    const size_t index = currentCommand.find(';');
    if (index == -1) {
        return "";
    }

    return currentCommand.substr(index, currentCommand.length() - 1);
}