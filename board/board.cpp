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
            round++;
        }
    }
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
