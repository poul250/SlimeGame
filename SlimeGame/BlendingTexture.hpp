#pragma once
#include <SFML/Graphics.hpp>
class BlendingTexture : public sf::Texture {
public:
	BlendingTexture(float radius, sf::Color color, int count = 1);
	~BlendingTexture();
private:
	sf::Image img;
	sf::RenderTexture rTexture;
};

