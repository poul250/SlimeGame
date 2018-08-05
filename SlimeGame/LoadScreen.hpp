#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
class LoadScreen :
	public State {
public:
	LoadScreen(std::shared_ptr<State> state);
	~LoadScreen();

	void update() override;
	void enterState() override;
protected:
	void draw(RenderTarget & target, RenderStates states) const override;
private:
	void init();

	std::shared_ptr<State> state;
	sf::Thread thread;
	int progress = 0;
	RectangleShape rect, progressRect, bg;
};

