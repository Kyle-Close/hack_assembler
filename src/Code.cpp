//
// Created by Kyle Close on 2026-03-16.
//

#include "../include/Code.h"

#include <iostream>
#include <string>

std::string Code::dest(const std::string& mnemonic) {
    if (mnemonic == "null") {
        return "000";
    } else if (mnemonic == "M") {
        return "001";
    } else if (mnemonic == "D") {
        return "010";
    } else if (mnemonic == "MD") {
        return "011";
    } else if (mnemonic == "A") {
        return "100";
    } else if (mnemonic == "AM") {
        return "101";
    } else if (mnemonic == "AD") {
        return "110";
    } else if (mnemonic == "AMD") {
        return "111";
    } else {
        std::cerr << "Invalid dest mnemonic." << std::endl;
        exit(EXIT_FAILURE);
    }
}

std::string Code::comp(const std::string& mnemonic) {
    if (mnemonic == "0") {
        return "0101010";
    } else if (mnemonic == "1") {
        return "0111111";
    } else if (mnemonic == "-1") {
        return "0111010";
    } else if (mnemonic == "D") {
        return "0001100";
    } else if (mnemonic == "A") {
        return "0110000";
    }else if (mnemonic == "M") {
        return "1110000";
    } else if (mnemonic == "!D") {
        return "0001111";
    } else if (mnemonic == "-A") {
        return "0110011";
    }else if (mnemonic == "-M") {
        return "1110011";
    } else if (mnemonic == "D+1") {
        return "011111";
    } else if (mnemonic == "A+1") {
        return "0110111";
    }else if (mnemonic == "D+1") {
        return "1110111";
    } else if (mnemonic == "D-1") {
        return "001110";
    } else if (mnemonic == "A-1") {
        return "0110010";
    }else if (mnemonic == "M-1") {
        return "1110010";
    } else if (mnemonic == "D+A") {
        return "0000010";
    }else if (mnemonic == "D+M") {
        return "1000010";
    }else if (mnemonic == "D-A") {
        return "0010011";
    }else if (mnemonic == "D-M") {
        return "1010011";
    } else if (mnemonic == "A-D") {
        return "0000111";
    } else if (mnemonic == "M-D") {
        return "1000111";
    } else if (mnemonic == "D&A") {
        return "0000000";
    }else if (mnemonic == "D&M") {
        return "1000000";
    } else if (mnemonic == "D|A") {
        return "0010101";
    }else if (mnemonic == "D|M") {
        return "1010101";
    } else {
        std::cerr << "Invalid comp mnemonic." << std::endl;
        exit(EXIT_FAILURE);
    }
}

std::string Code::jump(const std::string& mnemonic) {
    if (mnemonic == "null") {
        return "000";
    } else if (mnemonic == "JGT") {
        return "001";
    } else if (mnemonic == "JEQ") {
        return "010";
    } else if (mnemonic == "JGE") {
        return "011";
    } else if (mnemonic == "JLT") {
        return "100";
    } else if (mnemonic == "JNE") {
        return "101";
    } else if (mnemonic == "JLE") {
        return "110";
    } else if (mnemonic == "JMP") {
        return "111";
    } else {
        std::cerr << "Invalid jump mnemonic." << std::endl;
        exit(EXIT_FAILURE);
    }
}