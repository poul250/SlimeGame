#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Entity : public Drawable {
public:
	Entity();
	virtual ~Entity();
	virtual void update() = 0;
};