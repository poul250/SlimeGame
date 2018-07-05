#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include "State.hpp"

using namespace sf;

class StateManager : public Drawable {
public:
	StateManager(State *prevState);
	~StateManager();
	void update();
protected:
	void draw(RenderTarget& target, RenderStates renderStates) const override;
private:
	State* currState;
};