#include <iostream>
#include "LoadScreen.hpp"
#include "MainMenu.hpp"
#include "ButtonFactory.hpp"
#include "EmptyState.hpp"
#include "Game.hpp"
#include "Level1.hpp"

MainMenu::MainMenu()
	: bg(Vector2f(640, 360))
{
	bg.setPosition(0, 0);
	bg.setTexture(Assets::textures["menuBG"].get());
	bg.setTextureRect(IntRect(0, 0, 640, 360));
	RectangleShape button1(Vector2f(100, 50));
	RectangleShape button2 = button1, button3 = button1;
	ButtonFactory factory;
	button1.setPosition(200, 30);
	button2.setPosition(200, 100);
	button3.setPosition(200, 170);
	buttonManager.addButton(factory.create(button1, [&]() {
		replaceState(std::make_shared<LoadScreen>(std::make_shared<Level1>()));
	}));

	buttonManager.addButton(factory.create(button2, [&]() {
		addState(std::make_shared<EmptyState>());
	}));
	
	buttonManager.addButton(factory.create(button3, [&]() {
		Game::stop();
	}));

	if (!music.openFromFile("vtoroyogg.ogg")) {
		exit(-1);
	}
}

MainMenu::~MainMenu() 
{ }

void MainMenu::update() 
{
	buttonManager.update();
}

void MainMenu::enterState()
{
	music.play();
}

void MainMenu::leaveState()
{
	music.stop();
}

void MainMenu::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(bg, states);
	target.draw(buttonManager, states);
}
