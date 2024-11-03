//
// Created by aziz on 11/3/24.
//

#include <ui.h>


void ui::init_grid() {
    int gridSize = 4;
    int spacing = 30;

    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < gridSize; j++) {
            int index = gridSize * i + j;
            grid[index].position = sf::Vector2f(j * spacing, i * spacing);
            grid[index].color = sf::Color::Black;
        }
    }
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




