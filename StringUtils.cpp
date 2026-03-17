//
// Created by kyle on 2026-03-16.
//

#include <string>
#include "StringUtils.h"

void TrimStart(std::string& str) {
    if (str.empty()) {
        return;
    }

    int i = 0;
    while (i <= str.length() - 1 && std::isblank(str[i])) {
        i++;
    }

    if (i > 0) {
        str.erase(0, i);
    }
}

void TrimEnd(std::string& str) {
    if (str.empty()) {
        return;
    }

    size_t i = str.length() - 1;
    size_t count = 0;
    while (count < str.length() && std::isblank(str[i])) {
        i--;
        count++;
    }

    if (count > 0) {
        str.erase(str.length() - count, count);
    }
}

void Trim(std::string& str) {
    if (str.empty()) {
        return;
    }

    TrimStart(str);
    TrimEnd(str);
}