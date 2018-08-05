#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

using namespace sf;


class Entity : public Drawable {
public:
	Entity(FloatRect rect = FloatRect(0, 0, 0, 0));
	virtual ~Entity();
	virtual void update() = 0;

	bool isActive() const;
	virtual bool intersects(const Entity &another) const;
	virtual FloatRect getRect() const;
protected:
	FloatRect rect;
	bool active = true;
};

typedef std::shared_ptr<Entity> EntityPtr;
