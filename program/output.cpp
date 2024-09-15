#include "output.h"
#include <iostream>
#include <string>
#include "../user/user.h"

std::string output::get_username(const int id)
{
    std::string name;
    std::cout << "What's your name? user: " << id << std::endl;;
    std::cin >> name;
    return name;
}

int output::x_or_o(const int user)
{
    std::cout << "Do you want to be X or O?, user: " << user << std::endl;;
    return user;
}

void output::ask_to_enter_x_or_o()
{
    std::cout << "Please enter X or O..." << std::endl;;
}

void output::enter_index(const std::string& username)
{
    std::cout << "Current turn:"  << username << std::endl;;
    std::cout << "Enter any case that isn't filled (starting from 1)" << std::endl;;
}

bool output::repeat_request()
{

    char user1choice;
    std::cout << "user 1 do you want to restart?(y/n)" << std::endl;
    std::cin >> user1choice;

    char user2choice;
    std::cout << "user 2 do you want to restart?(y/n)" << std::endl;
    std::cin >> user2choice;

    if(std::tolower(user2choice) == 'y' && std::tolower(user1choice) == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }

}

void output::display_scores(user user)
{
    std::cout << "user " << user.get_name() << "'s score is: " << user.get_score() << std::endl;
}

void output::end_program()
{
    std::cout << "thank you for trying my program!" << std::endl;
}
