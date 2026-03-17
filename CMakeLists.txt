cmake_minimum_required(VERSION 4.1)
project(Assembler)

set(CMAKE_CXX_STANDARD 20)

add_executable(Assembler main.cpp Parser.cpp
        StringUtils.cpp)
