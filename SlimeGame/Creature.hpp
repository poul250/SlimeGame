#pragma once
#include <memory>
#include "Entity.hpp"

class Creature : public Entity
{
public:
	Creature(FloatRect rect);
	virtual ~Creature();
protected:
	int health;
	float vx, vy;
};

typedef std::shared_ptr<Creature> CreaturePtr;