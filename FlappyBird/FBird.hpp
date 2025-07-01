#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class FBird{
private:
sf::RenderWindow window;

public:
void run(), draw(), keys(), events();
FBird();
~FBird();



};
