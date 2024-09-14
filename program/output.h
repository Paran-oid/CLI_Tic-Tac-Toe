// output.h
#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>

class output
{
public:
    static std::string get_username(int);
    static int x_or_o(int);
    static void ask_to_enter_x_or_o();
    static void enter_index();
    static void enter_indexW();
};



#endif // OUTPUT_H
