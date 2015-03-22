#include <SFML/Graphics.hpp>
#include <iostream>
#include "config.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    std::cout << "Stuff which is buit in:\n";
    #ifdef USE_JOYSTICK
    std::cout << "Joystick support built in.\n";
    
    sf::Joystick::Identification joystickId = sf::Joystick::getIdentification(0);
    std::cout << "Vendor ID: " << joystickId.vendorId << std::endl << "Product ID: " << joystickId.productId << std::endl;
    #endif

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                std::cout << "Quit from <WindowManager>" << std::endl;
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                std::cout << "Quit from <ESC>" << std::endl;
            }
        }

        #ifdef USE_JOYSTICK
        if (sf::Joystick::isConnected(0)) {
            unsigned int buttonCount = sf::Joystick::getButtonCount(0);
        }
        #endif

        window.clear();
        window.display();
    }

    return 0;
}