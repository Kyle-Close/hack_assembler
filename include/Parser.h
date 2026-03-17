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
    [[nodiscard]] bool hasMoreCommands() const;
    void advance();
    [[nodiscard]] CommandType commandType() const;
    [[nodiscard]] std::string symbol() const;
    [[nodiscard]] std::string dest() const;
    [[nodiscard]] std::string comp() const;
    [[nodiscard]] std::string jump() const;
};

#endif //PARSER_H