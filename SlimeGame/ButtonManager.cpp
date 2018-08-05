#include "ButtonManager.hpp"

ButtonManager::ButtonManager()
{ }

ButtonManager::~ButtonManager()
{ }

void ButtonManager::addButton(UIButtonPtr button)
{
	buttons.push_back(button);
}

void ButtonManager::removeButton(UIButtonPtr button)
{

}

void ButtonManager::update()
{
	for (auto button : buttons) {
		button->update();
	}
}

void ButtonManager::draw(RenderTarget & target, RenderStates states) const
{
	for (auto button : buttons) {
		target.draw(*button, states);
	}
}