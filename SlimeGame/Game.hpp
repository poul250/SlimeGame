#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "StateManager.hpp"
using namespace std;
using namespace sf;

class Game {
public:
	Game(VideoMode vMode, string title);
	void start();
	static void stop();

	static int getWidth();
	static int getHeight();
	static string getTitle();
private:
	void update();
	void draw();

	static int width;
	static int height;
	static string title;

	static bool running;
	RenderWindow window;
	StateManager stateManager;
};