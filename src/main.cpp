
#include <cstdlib>
#include <iostream>
#include <bitset>

#include "../include/Parser.h"
#include "../include/Code.h"

int main(const int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Incorrect use of program. Expected: hack <input.asm>" << std::endl;
        exit(EXIT_FAILURE);
    }

    Parser parser(argv[1]);

    do {
        parser.advance();

        switch (parser.commandType()) {
            case A_COMMAND: {
                std::string binary = std::bitset<16>(std::stoi(parser.symbol())).to_string(); //to binary
                std::cout << binary << std::endl;
                break;
            }
            case C_COMMAND: {
                std::string binary = "111";
                binary += Code::comp(parser.comp());
                binary += Code::dest(parser.dest());
                binary += Code::jump(parser.jump());
                std::cout << binary << std::endl;
                break;
            }
            case L_COMMAND:
                std::cout << "Not implemented...";
                break;
        }
    } while (parser.hasMoreCommands());

    return 0;
}

