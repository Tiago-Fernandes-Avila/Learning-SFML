#include "FBird.hpp"
#include <iostream>

// forças
const float VELOCITY_Y = 0.04f;
const float STRENGTH_BIRD = 100.f;
// rotação
const float ROTACAO_PARA_CIMA = -35.0f;
const float VELOCIDADE_ROTACAO_QUEDA = 100.0f; // Graus por segundo
const float ANGULO_MAX_QUEDA = 90.0f;
// verificação
bool isPressed = false;

// tempo

    sf::Clock temporizador;
    sf::Time tempoDecorrido = sf::seconds(0.5f);

FBird::FBird() : window(sf::VideoMode(800, 600), "Flappy Bird"), texture(), birdSprite()
{ // incializando variaveis membros
    if (!texture.loadFromFile("assets/bird.png"))
    {
        std::cout << "bird sprite nao carregou!";
    }
    birdSprite.setTexture(texture);

    birdSprite.setOrigin(birdSprite.getTextureRect().width / 2, birdSprite.getTextureRect().height / 2);
    birdSprite.setPosition(360, 300);
    birdSprite.scale(0.05f, 0.05f);
}

FBird::~FBird()
{
    std::cout << "Destruindo o jogo na memoria" << std::endl;
}

void FBird::run()
{
    while (window.isOpen())
    { // ordem correta em um loop principal: eventos, logica e desenho
        events();
        logic();
        draw();
    }
}

void FBird::draw()
{

    window.clear(sf::Color(70, 190, 240)); // lembre-se primeiro limpe o quadro e depois renderize os desenhos
    window.draw(birdSprite);
    window.display();
}
void FBird::events()
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
        {
            if (!isPressed)
            {

                birdSprite.move(0, -STRENGTH_BIRD);
                if (birdSprite.getRotation() < ANGULO_MAX_QUEDA);
                {
                     birdSprite.rotate(ROTACAO_PARA_CIMA);
                }
                
              
                isPressed = true;
            }
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
        {
            isPressed = false;
        }
    }
}

void FBird::logic()
{

    birdSprite.move(0, VELOCITY_Y); // gravidade
    if (birdSprite.getPosition().y > 600)
    { // evita queda livre infinita!
        birdSprite.setPosition(360, 300);
    }


    if (temporizador.getElapsedTime().asSeconds() > tempoDecorrido.asSeconds())
    {
        birdSprite.rotate(1.f);
        if (birdSprite.getRotation() >= ANGULO_MAX_QUEDA)
        {
            birdSprite.setRotation(ANGULO_MAX_QUEDA);
        }
        
    }
    temporizador.restart();
}
