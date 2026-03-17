//
// Created by Kyle Close on 2026-03-16.
//

#ifndef CODE_H
#define CODE_H
#include <string>


class Code {
    public:
        static std::string dest(const std::string& mnemonic);
        static std::string comp(const std::string& mnemonic);
        static std::string jump(const std::string& mnemonic);
};


#endif //CODE_H