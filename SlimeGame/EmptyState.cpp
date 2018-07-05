#include "EmptyState.hpp"
#include "Game.hpp"

EmptyState::EmptyState()
	: rect(Vector2f(Game::getWidth(), Game::getHeight())) 
{ 
	rect.setFillColor(Color::Black);
	rect.setPosition(0, 0);
}
	
void EmptyState::update() 
{ }

void EmptyState::draw(RenderTarget & target, RenderStates states) const 
{ }
