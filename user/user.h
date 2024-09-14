#include <iostream>
#include <string>

#ifndef USER_H
#define USER_H



class user {
public:
    std::string get_name();
    void set_name(const std::string& name);

    void set_operator(char op);
private:
    std::string Name;
    char Op = ' ';
};



#endif //USER_H
