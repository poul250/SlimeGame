#include "BlendingTexture.hpp"

BlendingTexture::BlendingTexture(float radius, sf::Color color, int count = 1)
{ 
	rTexture.create(2 * radius, 2 * radius);
	rTexture.setSmooth(true);

	sf::CircleShape shape(radius);
	shape.setFillColor(color);
	sf::BlendMode blendMode = sf::BlendMode(sf::BlendMode::One, sf::BlendMode::One, sf::BlendMode::Add,
		sf::BlendMode::One, sf::BlendMode::One, sf::BlendMode::Add);

	for (int i = 0; i < count; ++i) {
		rTexture.draw(shape, blendMode);
		shape.setRadius(shape.getRadius() - 1);
		shape.setPosition(shape.getPosition().x + 1, shape.getPosition().y + 1);
	}
	sf::Image img = rTexture.getTexture().copyToImage();
	loadFromImage(img);
}

BlendingTexture::~BlendingTexture()
{ }
