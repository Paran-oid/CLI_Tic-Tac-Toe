#include <iostream>
#include <string>

#ifndef USER_H
#define USER_H



class user {
public:
    std::string get_name();
    void set_name(const std::string& name);
    char get_operator() const;
    void set_operator(char op);
    int get_score();
private:
    std::string Name;
    char Op = ' ';
    int Score = 0;
};



#endif //USER_H
