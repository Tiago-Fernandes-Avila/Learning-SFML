#include "FBird.hpp"

int main(){
    FBird* game = new FBird();
    
    
    game->run();


    delete game;
    return 0;
}