#include "State.hpp"

State::State() 
	: nextState(nullptr)
	, stateCond(STATE_GOOD)
{ }

State::~State() 
{ }

void State::init(int & progress)
{
    progress = 100;
}

void State::enterState() 
{ }

void State::leaveState() 
{ }

void State::setStateCond(StateCond cond, StatePtr next)
{
    stateCond = cond;
    nextState = next;
}

void State::stayState()
{
    stateCond = STATE_GOOD;
    nextState = nullptr;
}

void State::addState(StatePtr state)
{
    stateCond = ADD_STATE;
    nextState = state;
}

void State::removeState()
{
    stateCond = REMOVE_STATE;
}

void State::replaceState(StatePtr state)
{
    stateCond = REPLACE_STATE;
    nextState = state;
}
