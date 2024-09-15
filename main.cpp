#include <algorithm>
#include "user/user.h"
#include "./program/output.h"
#include <random>
#include <chrono>

#include "board/board.h"

int main()
{
    bool isRunning = true;
    char userInput = ' ';

    user user1;
    user user2;

    std::srand(std::chrono::steady_clock::now().time_since_epoch().count());
    int beginUser = std::rand() % 2 + 1;

    while(isRunning)
    {
        user1.set_name(output::get_username(1));
        user2.set_name(output::get_username(2));
        int user = output::x_or_o(beginUser);

        std::cin >> userInput;
        while(userInput != 'X' && userInput != 'O')
        {
            output::ask_to_enter_x_or_o();
            std::cin >> userInput;
        }

        if(user == 1)
        {
            user1.set_operator(std::toupper(userInput));
            user2.set_operator(userInput == 'X' ? 'O' : 'X');
        }
        else
        {
            user2.set_operator(std::toupper(userInput));
            user1.set_operator(userInput == 'X' ? 'O' : 'X');
        }

        board::run_game(user1, user2);

        bool repeat = output::repeat_request();
        if(repeat == false)
        {
            isRunning = false;
            output::display_scores(user1);
            output::display_scores(user2);
        }
        else
        {
            output::display_scores(user1);
            output::display_scores(user2);
        }

    }

    output::end_program();
}
