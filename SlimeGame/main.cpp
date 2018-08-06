#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main() 
{
    Game * game = Game::getGame(640, 360, 3, "Nori");
    game->start();

    return 0;
}