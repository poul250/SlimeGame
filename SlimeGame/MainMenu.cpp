#include "MainMenu.hpp"

MainMenu::MainMenu(State *prev) 
	: State(prev) 
{ }

MainMenu::~MainMenu() 
{ }

void MainMenu::update() 
{
	menuBG.update();
}

void MainMenu::draw(RenderTarget & target, RenderStates states) const 
{
	target.draw(menuBG, states);
}


MenuBackGround::MenuBackGround() 
	: rect(Vector2f(100, 100)) 
{
	rect.setPosition(Vector2f(100, 100));
	rect.setFillColor(Color::White);
	
	if (!font.loadFromFile("font.ttf"))
		exit(-1);
	text.setFont(font);
	text.setString("Slime");
	text.setCharacterSize(50);
	text.setFillColor(Color::White);
	text.setStyle(Text::Bold);
	text.setPosition(300, 300);
}

MenuBackGround::~MenuBackGround() 
{ }

void MenuBackGround::update() 
{ }

void MenuBackGround::draw(RenderTarget & target, RenderStates states) const 
{
	target.draw(text, states);
}
