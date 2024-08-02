cmake_minimum_required(VERSION 3.28)
project(Kolko_i_krzyzyk)

set(CMAKE_CXX_STANDARD 26)

add_executable(Kolko_i_krzyzyk main.cpp
        board.h
        ai.h
        ai.cpp
        board.cpp)
