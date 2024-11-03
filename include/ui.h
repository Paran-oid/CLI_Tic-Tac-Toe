//
// Created by aziz on 11/3/24.
//

#ifndef UI_H
#define UI_H
#include <SFML/Graphics.hpp>

class ui {
public:
    ui()
        :window(sf::VideoMode(1000, 1000), "Tic Tac Toe"),
        grid(sf::Lines, 16)
    {}
    void loop();
    void init_grid();

private:
    sf::RenderWindow window;
    sf::VertexArray grid;
};


#endif //UI_H
