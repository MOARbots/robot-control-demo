#include <SFML/Graphics.hpp>
#include <iostream>
#include "config.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    std::cout << "Stuff which is buit in:\n";
    #ifdef USE_JOYSTICK
    std::cout << "Joystick support built in.\n";
    #endif

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        #ifdef USE_JOYSTICK
        if (sf::Joystick::isConnected(0)) {
            
        }
        #endif

        window.clear();
        window.display();
    }

    return 0;
}