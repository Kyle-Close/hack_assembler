
#include <cstdlib>
#include <iostream>

#include "../include/Parser.h"

int main(const int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Incorrect use of program. Expected: hack <input.asm>" << std::endl;
        exit(EXIT_FAILURE);
    }

    Parser parser(argv[1]);

    return 0;
}

