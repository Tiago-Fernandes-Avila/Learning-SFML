#include "FBird.hpp"
#include <iostream>


FBird::FBird() : window(sf::VideoMode(1000, 600), "Flappy Bird"),bird(), bg(), pipe(), birdSprite(), bgSprite(), pipeSprite(), VELOCITY_Y(0.04f), STRENGTH_BIRD(100.f), ROTACAO_PARA_CIMA(-35.0f), VELOCIDADE_ROTACAO_QUEDA(100.0f), ANGULO_MAX_QUEDA(90.0f), isPressed(false), animaInterval(sf::seconds(0.1f)){ // incializando variaveis membros
   
    if (!bg.loadFromFile("assets/background.png") || !bird.loadFromFile("assets/flappy.png") ||  !pipe.loadFromFile("assets/pipe.png"))
    {
        std::cout << "algum asset nao carregou!";
    }
    pipeSprite.setTexture(pipe);
    birdSprite.setTexture(bird);
    bgSprite.setTexture(bg);
    birdSprite.setOrigin(birdSprite.getTextureRect().width / 2, birdSprite.getTextureRect().height / 2);

    sf::IntRect frames [3]= {
        sf::IntRect(0, 0, 34, 24),
        sf::IntRect(34, 0, 34, 24),
        sf::IntRect(68, 0, 34, 24)
    };
    birdSprite.setTextureRect(frames[0]);

   

    bgSprite.setPosition(0.f, 0.0f);
    birdSprite.setPosition(360, 300);

   

    
}

FBird::~FBird()
{
    std::cout << "Destruindo o jogo na memoria" << std::endl;
}

void FBird::run()
{
    

    while (window.isOpen())
    {
      // ordem correta em um loop principal: eventos, logica e desenho
        events();
        logic();
        draw();

       
        
    }
}

void FBird::draw()
{

    window.clear(sf::Color(70, 190, 240)); // lembre-se primeiro limpe o quadro e depois renderize os desenhos
      window.draw(bgSprite);
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
                isPressed = true;
                if (birdSprite.getRotation() < ANGULO_MAX_QUEDA);
                {
                     birdSprite.setRotation(-20.0f);
                }
                
            }
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
        {
            isPressed = false;
            birdSprite.setRotation(0.0f);
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
    if(birdSprite.getPosition().x < 0.0f ){
        birdSprite.setPosition(birdSprite.getPosition().x, 5.0f);
    }



}


void FBird::animations(){ //devo escrever um codigo onde em certo e certo tempo eu troque de sprite no array 

}
