#include "Entity.hpp"

Entity::Entity(FloatRect rect) 
    : rect(rect)
{ }

Entity::~Entity() 
{ }

bool Entity::isActive() const
{
    return active;
}

bool Entity::intersects(const Entity &another) const
{
    return rect.intersects(another.rect);
}

FloatRect Entity::getRect() const
{
    return rect;
}