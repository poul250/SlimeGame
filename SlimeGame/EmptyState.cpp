#include "EmptyState.hpp"
#include "Assets.hpp"

EmptyState::EmptyState()
    : rect(Vector2f(Assets::getWidth(), Assets::getHeight())) 
{ 
    rect.setFillColor(Color::Black);
    rect.setPosition(0, 0);
}
	
void EmptyState::update() 
{ }

void EmptyState::draw(RenderTarget & target, RenderStates states) const 
{ }
