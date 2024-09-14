cmake_minimum_required(VERSION 3.29)
project(Tic_Tac_Toe)

set(CMAKE_CXX_STANDARD 26)

add_executable(Tic_Tac_Toe main.cpp
        board/board.cpp
        board/board.h
        program/output.cpp
        ai/ai.cpp
        ai/ai.h
        user/user.cpp
        user/user.h
        program/output.h
)
