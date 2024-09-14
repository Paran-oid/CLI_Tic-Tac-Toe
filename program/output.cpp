#include "output.h"
#include <iostream>
#include <string>

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

void output::enter_index()
{
    std::cout << "Enter any case that isn't filled (starting from 1)" << std::endl;;
}

void output::enter_indexW()
{
    std::cout << "PLEASE enter any case that isn't filled (starting from 1)" << std::endl;;
}
