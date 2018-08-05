#pragma once
#include <SFML/Graphics.hpp>
class BlendingCircle : public sf::CircleShape {
public:
	BlendingCircle(float radius, sf::Color color, int count = 1);
	~BlendingCircle();

private:
	sf::RenderTexture rTexture;
	sf::Texture texture;
};

