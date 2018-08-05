#include "BlendingCircle.hpp"

BlendingCircle::BlendingCircle(float radius, sf::Color color, int count)
	: CircleShape(radius)
{
	rTexture.create(2 * radius, 2 * radius);
	rTexture.setSmooth(true);

	CircleShape shape(radius);
	shape.setFillColor(color);
	sf::BlendMode blendMode = sf::BlendMode(sf::BlendMode::One, sf::BlendMode::One, sf::BlendMode::Add, 
		sf::BlendMode::One, sf::BlendMode::One, sf::BlendMode::Add);

	for (int i = 0; i < count; ++i) {
		rTexture.draw(shape, blendMode);
		shape.setRadius(shape.getRadius() - 1);
		shape.setPosition(shape.getPosition().x + 1, shape.getPosition().y + 1);
	}
	setTextureRect(sf::IntRect(0, 0, 2 * radius, 2 * radius));
	texture = rTexture.getTexture();
	setTexture(&texture);
}

BlendingCircle::~BlendingCircle()
{ }
