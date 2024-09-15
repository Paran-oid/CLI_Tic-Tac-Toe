// output.h
#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>
#include "../user/user.h"

class output
{
public:
    static std::string get_username(int);
    static int x_or_o(int);
    static void ask_to_enter_x_or_o();
    static void enter_index(const std::string& username);
    static bool repeat_request();
    static void display_scores(user user);
    static void end_program();

};



#endif // OUTPUT_H