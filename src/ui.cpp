//
// Created by aziz on 11/3/24.
//

#include <ui.h>


void ui::init_grid() {
}

void ui::loop() {
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::White);
        //program
        init_grid();

        window.draw(grid);
        window.display();
    }
}




