#include <iostream>
#include <vector>
#include <algorithm>
#include "board.h"
#include "../program/output.h"
#include "../user/user.h"

std::vector<char> board::Body(9, ' ');
bool board::GameOn = false;

void board::run_game(const user& user1,const user& user2)
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
            std::optional<user> winner = board::check(user1, user2);
            if(winner)
            {
                result = "We have a winner:" + winner-> get_name();
                break;
            }
            else
            {
                round++;
            }
        }
    }
    std::string_view res(result);
    output::display_result(res);
    print_board();
}
void board::ai_input()
{

}
void board::user_input(user user)
{
    int answer;
    output::enter_index(user.get_name());
    print_board();

    std::cin >> answer;

    while(answer < 1)
    {
        output::enter_index(user.get_name());
        std::cin >> answer;
        print_board();
    }

    while(Body[answer - 1] != ' ')
    {
        output::enter_index(user.get_name());
        print_board();
        std::cin >> answer;
    }

    Body[answer - 1] = user.get_operator();
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
        if(res[i-1] != res[i] || res[i] == ' ')
        {
            return false;
        }
    }
    return true;
}

std::optional<user> board::check(const user& user1, const user& user2)
{
    std::string temp = "";
    int offset = 0;
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp += Body[j + offset];
        }
        if(is_valid(temp))
        {
            //need to stop this pattern here
            user winner = user1.get_operator() == temp[0] ? user1 : user2;
            return winner;
        }
        temp = "";
        offset += 3;
    }

    temp = "";
    offset = 0;

    for(int j = 0; j < 3; j++)
    {
        for(int i = 0; i < 3; i++)
        {
            temp += Body[i + offset];
        }
        if(is_valid(temp))
        {
            user winner = user1.get_operator() == temp[0] ? user1 : user2;
            return winner;
        }
        temp = "";
        offset += 3;
    }

    if(is_valid(temp))
    {
        user winner = user1.get_operator() == temp[0] ? user1 : user2;
        return winner;
    }
    temp = Body[2] + Body[5] + Body[7];
    if(is_valid(temp))
    {
        user winner = user1.get_operator() == temp[0] ? user1 : user2;
        return winner;
    }

    return std::nullopt;
}

