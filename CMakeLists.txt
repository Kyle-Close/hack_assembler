cmake_minimum_required(VERSION 4.1)
project(Assembler)

set(CMAKE_CXX_STANDARD 20)

add_executable(Assembler
        src/main.cpp
        src/Parser.cpp
        src/StringUtils.cpp)
