cmake_minimum_required(VERSION 3.21)
project(parsers_enz)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(parsers_enz
        main.cpp
        AST.cpp
        AST.h
        ShuntingYardParser.cpp
        ShuntingYardParser.h
        )
