#include "Entity.hpp"

Entity::Entity(FloatRect rect)
    : RectangleShape(Vector2f(rect.width, rect.height))
{
    setPosition(rect.left, rect.top);
}

Entity::~Entity()
{ }

bool Entity::isActive() const
{
    return active;
}

bool Entity::interactsWithEnv()
{
    return false;
}