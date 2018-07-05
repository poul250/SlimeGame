#include "State.hpp"

State::State(State *prev) 
{
	prevState = prev;
	nextState = this;
}
State::~State() 
{ }
	
void State::endState() 
{
	done = true;
}

void State::setNextState(State *state) 
{
	nextState = state;
}

void State::enterState() 
{
	done = false;
	nextState = this;
}
void State::leaveState() 
{ }
