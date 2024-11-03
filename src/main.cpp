#include <algorithm>
#include <random>
#include <chrono>
#include <memory>
#include "ui.h"

#include "board.h"
#include "user.h"
#include "output.h"

int main() {
    auto interface = std::make_unique<ui>();
    interface->loop();
}

/*int main()
{
    bool isRunning = true;
    char userInput = ' ';

    std::unique_ptr<user> user1;
    std::unique_ptr<user> user2;

    int beginUser;
    //assign the user who will begin
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution uid(1, 2);
        beginUser = uid(mt);
    }

    while(isRunning)
    {
        user1->set_name(output::get_username(1));
        user2->set_name(output::get_username(2));
        const int user = output::x_or_o(beginUser);

        std::cin >> userInput;
        while(userInput != 'X' && userInput != 'O')
        {
            output::ask_to_enter_x_or_o();
            std::cin >> userInput;
        }

        if(user == 1)
        {
            user1->set_operator(std::toupper(userInput));
            user2->set_operator(userInput == 'X' ? 'O' : 'X');
        }
        else
        {
            user2->set_operator(std::toupper(userInput));
            user1->set_operator(userInput == 'X' ? 'O' : 'X');
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
}*/
