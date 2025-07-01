#include "FBird.hpp"
#include <iostream>

//Variaveis


FBird::FBird() :window(sf::VideoMode(800, 600), "Flappy Bird") { //incializando variaveis membros
    
  
}


FBird::~FBird(){
    std::cout << "Destruindo o jogo na memoria" << std::endl;
}


void FBird::run(){
    while(window.isOpen()){
        draw();
        keys();
        events();
}
   

}

void FBird::draw(){
    sf::Texture texture;
    texture.loadFromFile("bird.png");
    

    sf::Sprite birdSprite;
    birdSprite.setTexture(texture);
    birdSprite.setPosition(330, 400);
    birdSprite.setScale(0.2, 0.2);
    


window.draw(birdSprite);

  window.clear(sf::Color::Black);
  window.display();   

}
void FBird::events(){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
    }
}


void FBird::keys(){

}