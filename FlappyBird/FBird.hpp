#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class FBird{
private:
sf::RenderWindow window;
sf::Sprite birdSprite;
sf::Texture texture;

public:
void run(), draw(), keys(), events(), logic();
FBird();
~FBird();



};
