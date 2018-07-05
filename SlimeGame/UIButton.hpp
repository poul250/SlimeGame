#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
class UIButton : public Entity
{
public:
	UIButton();
	~UIButton();
private:
	RectangleShape rect;
	bool isActive();
	int x;
};

