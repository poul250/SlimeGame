#include "Creature.hpp"

Creature::Creature(FloatRect rect)
    : Entity(rect)
    , vx(0)
    , vy(0)
    , health(1)
{ }

Creature::~Creature()
{ }
