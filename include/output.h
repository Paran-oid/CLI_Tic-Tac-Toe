// output.h
#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>
#include <memory>

#include "user.h"

class output
{
public:
    static std::string get_username(int id);
    static int x_or_o(int);
    static void ask_to_enter_x_or_o();
    static void enter_index(const std::string& username);
    static bool repeat_request();

    static void display_scores(std::unique_ptr<user> &user);
    static void display_result(std::string_view res);
    static void end_program();

};



#endif // OUTPUT_H
