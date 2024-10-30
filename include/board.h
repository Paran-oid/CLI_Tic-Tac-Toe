#include <vector>
#include <memory>

#include "user.h"

#ifndef BOARD_H
#define BOARD_H


class board {
public:
    static void run_game(std::unique_ptr<user> &user1,std::unique_ptr<user> &user2);
    static std::optional<std::unique_ptr<user>> check(std::unique_ptr<user> &user1, std::unique_ptr<user> &user2);
    static void print_board();
    static void user_input(std::unique_ptr<user> &user);
    static void ai_input();
    static bool is_valid(const std::string& res);

private:
    static std::vector<char> Body;
    static bool GameOn;
};


#endif //BOARD_H
