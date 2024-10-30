#include <iostream>
#include <vector>
#include <algorithm>

#include "board.h"
#include "output.h"
#include "user.h"

std::vector<char> board::Body(9, ' ');
bool board::GameOn = false;

void board::run_game(std::unique_ptr<user> &user1,std::unique_ptr<user> &user2)
{
    GameOn = true;
    int round = 1;
    std::string result = "It's a draw";
    while(GameOn)
    {
        auto it = std::find(Body.begin(), Body.end(), ' ');
        if(it == Body.end())
        {
            GameOn = false;
        }
        else
        {
            if(round % 2 == 0)
            {
                user_input(user2);
            }
            else
            {
                user_input(user1);
            }
            auto winner = board::check(user1, user2);
            if(winner)
            {
                result = "We have a winner!! \n it's: " + winner->get()->get_name();
                break;
            }
            else
            {
                round++;
            }
        }
    }
    system("clear");
    std::string_view res(result);
    output::display_result(res);
}
void board::ai_input()
{

}
void board::user_input(std::unique_ptr<user> &user)
{
    int answer;
    output::enter_index(user->get_name());
    print_board();

    std::cin >> answer;

    while(answer < 1)
    {
        output::enter_index(user->get_name());
        std::cin >> answer;
        print_board();
    }

    while(Body[answer - 1] != ' ')
    {
        output::enter_index(user->get_name());
        print_board();
        std::cin >> answer;
    }

    Body[answer - 1] = user->get_operator();
}
void board::print_board()
{
    int counter = 0;
    for(size_t i = 0; i < Body.size(); i++)
    {
        std::cout << Body[i] << "||";
        counter++;
        if(counter == 3)
        {
            counter = 0;
            std::cout << std::endl;
        }
    }
}
bool board::is_valid(const std::string& res)
{
    if (res.length() != 3) return false;
    for(int i = 1; i < res.length(); i++)
    {
        if(res[i-1] != res[i] || res[i] == ' ' || res[i] == '\0')
        {
            return false;
        }
    }
    return true;
}
std::optional<std::unique_ptr<user>> board::check(std::unique_ptr<user> &user1, std::unique_ptr<user> &user2) {
    std::string temp;

    // Check rows
    for (int i = 0; i < 3; i++) {
        temp = "";
        for (int j = 0; j < 3; j++) {
            temp += Body[i * 3 + j]; // Correct row indexing
        }
        if (is_valid(temp)) {
            return (user1->get_operator() == temp[0]) ? std::make_unique<user>(*user1) : std::make_unique<user>(*user2);
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        temp = "";
        for (int i = 0; i < 3; i++) {
            temp += Body[i * 3 + j]; // Correct column indexing
        }
        if (is_valid(temp)) {
            return (user1->get_operator() == temp[0]) ? std::make_unique<user>(*user1) : std::make_unique<user>(*user2);
        }
    }

    // Check diagonals
    temp = {Body[0], Body[4], Body[8]};
    if (is_valid(temp)) {
        return (user1->get_operator() == temp[0]) ? std::make_unique<user>(*user1) : std::make_unique<user>(*user2);
    }
    temp = {Body[2], Body[4], Body[6]};
    if (is_valid(temp)) {
        return (user1->get_operator() == temp[0]) ? std::make_unique<user>(*user1) : std::make_unique<user>(*user2);
    }

    // No winner found
    return std::nullopt;
}