#include "Dot.hpp"

Dot::Dot(sf::Color color) :
	sf::RectangleShape (
		sf::Vector2f (
			2,
			2
		)
	),
	color (
		color
	)
{
	reset();
	lifeTime = rand() % maxLifeTime;
	updateColor();
}

Dot::~Dot()
{ }

void Dot::reset()
{
	lifeTime = 0;
	dead = false;
	speed = sf::Vector2f(float(-50 + rand() % 100) / 50 * maxSpeed,
						 float(-50 + rand() % 100) / 50 * maxSpeed);
	maxLifeTime = (LIFE_LIMIT / 2) + rand() % (LIFE_LIMIT / 2);
	updateColor();
}

void Dot::update()
{
	move(speed);
	
	if (lifeTime < maxLifeTime) {
		++lifeTime;
		updateColor();
	} else {
		dead = true;
	}
}

bool Dot::isDead() const
{
	return dead;
}

void Dot::setMaxSpeed(float speed)
{
	maxSpeed = speed;
}

void Dot::setColor(sf::Color color)
{
	this->color = color;
	updateColor();
}

void Dot::updateColor()
{
	float mul = float((lifeTime <= maxLifeTime / 2) * lifeTime +
		(lifeTime > maxLifeTime / 2) * (maxLifeTime - lifeTime)) / (maxLifeTime / 2);
	color.a = MAX_ALPHA * mul;
	setFillColor(color);
}
