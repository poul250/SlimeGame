#include <iostream>
#include <string>
#include "Game.hpp"
#include "MainMenu.hpp"
#include "Assets.hpp"

bool Game::running;
Game *Game::instance;

Game * Game::getGame(int width, int height, int scale, string title)
{
    if (!instance) {
        instance = new Game(width, height, scale, title);
    }
    return instance;
}

Game::Game(int width, int height, int scale, string title) 
    : window(VideoMode(width * scale, height * scale), title, Style::Close, ContextSettings(24, 0, 16))
{
    Assets::init(width, height, scale, &window);
    window.setFramerateLimit(60);
    auto settings = window.getSettings();
    settings.antialiasingLevel = 2;
	
    renderStates.transform *= Transform().scale(Vector2f(3, 3));
    stateManager.addState(std::make_shared<MainMenu>());

    instance = this;
}

void Game::start() 
{
    running = true;
	
    sf::Time time;
    sf::Clock clock;
    int upd = 0;
    while (running) {
        time += clock.getElapsedTime();
        clock.restart();
        upd++;
        while (time >= sf::seconds(1)) {
            std::cout << "fps:" << upd << "\n";
            time -= sf::seconds(1);
            upd = 0;
	}
		
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                running = false;
                break;
            case Event::LostFocus:
                stateManager.lostFocus();
                break;
            case Event::GainedFocus:
                stateManager.gainedFocus();
                break;
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
    window.draw(stateManager, renderStates);
    window.display();
}
