//
// Created by aziz on 9/14/24.
//

#include "user.h"
void user::set_name(const std::string& name)
{
    Name = name;
}

std::string user::get_name()
{
    return Name;
}

void user::set_operator(const char op)
{
    Op = op;
}

char user::get_operator() const
{
    return Op;
}

int user::get_score()
{
    return Score;
}

