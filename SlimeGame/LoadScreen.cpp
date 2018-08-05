#include "LoadScreen.hpp"

LoadScreen::LoadScreen(std::shared_ptr<State> state)
	: state(state)
	, bg(Vector2f(640, 360))
	, rect(Vector2f(150, 20))
	, progressRect(Vector2f(0, 20))
	, thread(&LoadScreen::init, this)
{ 
	bg.setFillColor(Color::Black);
	rect.setPosition(100, 100);
	rect.setFillColor(Color::Black);
	rect.setOutlineColor(Color::White);
	rect.setOutlineThickness(5);
	progressRect.setPosition(100, 100);
	progressRect.setFillColor(Color::White);
}

LoadScreen::~LoadScreen()
{ }

void LoadScreen::update()
{
	if (progress == 100 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		replaceState(state);
	}
	progressRect.setSize(Vector2f(150.0f * progress / 100, 20));
}

void LoadScreen::enterState()
{
	thread.launch();
}

void LoadScreen::draw(RenderTarget & target, RenderStates states) const
{ 
	target.draw(bg, states);
	target.draw(rect, states);
	target.draw(progressRect, states);
}

void LoadScreen::init()
{
	state->init(progress);
}
