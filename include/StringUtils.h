//
// Created by kyle on 2026-03-16.
//

#ifndef STRINGUTILS_H
#define STRINGUTILS_H
#include <string>

void TrimStart(std::string& str);
void TrimEnd(std::string& str);
void Trim(std::string& str);

bool StartsWith(const std::string& str, char target);
bool Contains(const std::string& str, char target);

#endif //STRINGUTILS_H