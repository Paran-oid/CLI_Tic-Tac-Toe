#include <iostream>
#include <vector>
#include "board.h"
#include "../program/output.h"

std::vector<char> board::Body(9, ' ');

void board::ai_input()
{

}
void board::user_input(const char op)
{
    int answer;
    output::enter_index();
    print_board();

    std::cin >> answer;

    while(answer < 1)
    {
        output::enter_index();
        std::cin >> answer;
    }

    while(Body[answer - 1] != ' ')
    {
        output::enter_indexW();
        print_board();
    }

    Body[answer - 1] = op;
}
void board::print_board()
{
    for(size_t i = 0; i < Body.size(); i++)
    {
        std::cout << Body[i];
        if(i + 1 / 3 == 0)
        {
            std::cout << std::endl;
        }
    }
}
