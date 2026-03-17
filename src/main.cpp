
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <fstream>

#include "../include/Parser.h"
#include "../include/Code.h"

int main(const int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Incorrect use of program. Expected: hack <input.asm>" << std::endl;
        exit(EXIT_FAILURE);
    }

    Parser parser(argv[1]);

    std::string fileName = argv[1];
    std::ofstream outFile(fileName.substr(0, fileName.rfind('.')) + ".hack");

    if (!outFile.is_open()) {
        std::cerr << "Failed to create file" << std::endl;
        return EXIT_FAILURE;
    }

    do {
        parser.advance();

        switch (parser.commandType()) {
            case A_COMMAND: {
                std::string binary = std::bitset<16>(std::stoi(parser.symbol())).to_string(); //to binary
                outFile << binary << std::endl;
                break;
            }
            case C_COMMAND: {
                std::string binary = "111";
                binary += Code::comp(parser.comp());
                binary += Code::dest(parser.dest());
                binary += Code::jump(parser.jump());
                outFile << binary << std::endl;
                break;
            }
            case L_COMMAND:
                std::cout << "Not implemented..." << std::endl;
                break;
        }
    } while (parser.hasMoreCommands());

    return 0;
}

