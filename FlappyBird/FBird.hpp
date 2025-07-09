#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <memory>
#include<vector>
#include <cmath>
class FBird{
private:


bool isColliding();
bool gameover;


//janela

sf::Clock timeInterval();
sf::RenderWindow window;

float SPACE_BETWEEN_PIPES = 160.f;
sf::Clock deltaClock;
float gravity1 = 980.f;
float velocity_y1 = 0;
float deltaTime;

//audio



//animação

std::vector<sf::IntRect> frames; // 
int currentFrame; // frame atual do sprite
sf::Clock animationClock; 

sf::Time animaInterval;//tempo até trocar o sprite
//sf::Clock clock;
//float deltaTime;

//entidades pipes
std::vector <sf::Sprite> pipesArray; //
float alturaCanos = 140;


//assets
sf::Texture bg, pipe, bird, gameOver;
sf::Sprite birdSprite, bgSprite, pipeSpriteBottom, pipeSpriteTop;

sf::Sprite gameOverSprite;



sf::Clock timeEachPipe;

int count, score;

//funçoes auxiliares
void update();
void jump();

void birdMove();


public:
void run(), draw(), keys(), events(), logic();
void scoreLogic();
FBird();
~FBird();


//spawn pipes
void printPipes();
void spawnPipes();


void reloadGame();
protected:
void animations();
sf::Font font;
sf::Text text;
sf::Text GameOverText;
};

