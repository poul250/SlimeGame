#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"

using namespace std;
using namespace sf;

int main() 
{
	Game game(VideoMode(512, 360), "Slime");
	game.start();

	return 0;
}