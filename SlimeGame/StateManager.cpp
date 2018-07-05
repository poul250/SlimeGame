#include "StateManager.hpp"
#include "EmptyState.hpp"

StateManager::StateManager(State *firstState) 
{
	currState = firstState;
}
StateManager::~StateManager() 
{

}
void StateManager::update() 
{
	if (currState->done) {
		currState->done = false;
		currState->nextState = currState;
		currState = currState->prevState;
		currState->nextState = currState;
	} else {
		currState = currState->nextState;
	}
	currState->update();
}
void StateManager::draw(RenderTarget &target, RenderStates renderStates) const 
{
	target.draw(*currState);
}