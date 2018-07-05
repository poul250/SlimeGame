#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class State : public Drawable {
public:
	friend class StateManager;

	State(State *prev = nullptr);
	virtual ~State();
	virtual void update() = 0;
protected:
	void endState();
	void setNextState(State *state);

	virtual void enterState();
	virtual void leaveState();
private:
	bool done;
	State *prevState;
	State *nextState;
};

