cmake_minimum_required(VERSION 3.29)
project(Tic_Tac_Toe)

set(CMAKE_CXX_STANDARD 26)

set(SRC
        src/main.cpp
        src/output.cpp
        src/user.cpp
        src/board.cpp)


set(INCLUDE_DIR
    include)

add_executable(Tic_Tac_Toe
    ${SRC}
)
target_include_directories(Tic_Tac_Toe PRIVATE ${INCLUDE_DIR})
target_link_libraries(Tic_Tac_Toe PRIVATE sfml-graphics sfml-audio sfml-window sfml-system)
