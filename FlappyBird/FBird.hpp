#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>

class FBird{
private:
//janela
sf::RenderWindow window;

//fisica e estados do jogo
const float VELOCITY_Y = 0.04f;
const float STRENGTH_BIRD = 100.f;
// rotação
const float ROTACAO_PARA_CIMA = -35.0f;
const float VELOCIDADE_ROTACAO_QUEDA = 100.0f; // Graus por segundo
const float ANGULO_MAX_QUEDA = 90.0f;
// verificação
bool isPressed = false;

//animação
std::vector<sf::IntRect> frames;
int currentFrame;
sf::Clock animationClock;
sf::Time animaInterval;


//assets
sf::Texture bg, pipe, bird;
sf::Sprite birdSprite, bgSprite, pipeSprite;

//funçoes auxiliares
void update(sf::Time dt);
void jump();



public:
void run(), draw(), keys(), events(), logic();
FBird();
~FBird();

protected:
void animations();

};
