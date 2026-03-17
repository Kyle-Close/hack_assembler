//
// Created by kyle on 2026-03-16.
//

#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector>

enum CommandType {
    A_COMMAND,
    C_COMMAND,
    L_COMMAND
};

class Parser {
public:
    std::vector<std::string> lines;
    std::string currentCommand;
    unsigned int currentCommandNumber = 0;

    explicit Parser(const std::string& filePath);
    bool hasMoreCommands() const;
    void advance();
    CommandType commandType();
    std::string symbol();
    std::string dest();
    std::string comp();
    std::string jump();
};

#endif //PARSER_H