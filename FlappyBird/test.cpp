#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

int main(){ 
    sf::RenderWindow window(sf::VideoMode(800, 600), "Flappy Bird");
    window.setFramerateLimit(60);
    window.clear(sf::Color::White);
    while(window.isOpen()){

    }
   return 0;
}