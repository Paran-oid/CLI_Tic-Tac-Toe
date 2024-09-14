#include <vector>

#ifndef BOARD_H
#define BOARD_H


class board {
public:
    static void print_board();
    static void user_input(char op);
    static void ai_input();

private:
    static std::vector<char> Body;
};


#endif //BOARD_H
