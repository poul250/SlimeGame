#include "StateManager.hpp"
#include "EmptyState.hpp"

StateManager::StateManager() 
{ }

StateManager::~StateManager() 
{ }

void StateManager::addState(StatePtr state)
{
    states.push(state);
    state->enterState();
}

void StateManager::update() 
{
    states.top()->update();
    StatePtr next = states.top()->nextState;
    switch (states.top()->stateCond) {
    case State::STATE_GOOD:
        break;
    case State::ADD_STATE:
        states.top()->stayState();
        states.top()->leaveState();
        states.push(next);
        next->enterState();
        break;
    case State::REMOVE_STATE:
        states.top()->leaveState();
        states.pop();
        states.push(next);
        next->enterState();
        break;
    case State::REPLACE_STATE:
        states.top()->leaveState();
        states.pop();
        states.push(next);
        next->enterState();
        break;
    }
}

void StateManager::draw(RenderTarget &target, RenderStates renderStates) const 
{
    target.draw(*states.top(), renderStates);
}