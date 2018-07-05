#include <string>
#include "Game.hpp"
#include "EmptyState.hpp"
#include "MainMenu.hpp"

int Game::width;
int Game::height;
std::string Game::title;
bool Game::running;

Game::Game(VideoMode vMode, string title)
	: window(vMode, title)
	, stateManager(new MainMenu(new EmptyState()))
{
	Game::width = width;
	Game::height = height;
	Game::title = title;
	window.setFramerateLimit(60);
}

void Game::start() 
{
	running = true;
	while (running) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				running = false;
			}
		}
		update();
		draw();
	}
	if (window.isOpen()) {
		window.close();
	}
}

void Game::stop() 
{
	running = false;
}

void Game::update() 
{
	stateManager.update();
}

void Game::draw() 
{
	window.clear(sf::Color::Black);
	window.draw(stateManager);
	window.display();
}

//Getters
int Game::getWidth()    { return width; }
int Game::getHeight()   { return height;}
string Game::getTitle() { return title; }