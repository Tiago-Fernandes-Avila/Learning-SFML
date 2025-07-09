#include "FBird.hpp"

int main(){

    std::srand(std::time(NULL));

    FBird* game = new FBird();
    game->run();


    delete game;
    return 0;
}