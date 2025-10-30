cmake_minimum_required(VERSION 3.31)
project(tic_tac_toe_console)

set(CMAKE_CXX_STANDARD 20)

add_executable(tic_tac_toe_console main.cpp
        player.cpp
        player.h
        board.cpp
        board.h
        ai.cpp
        ai.h)
