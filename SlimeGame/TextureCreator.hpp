#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
class TextureCreator {
public:
	TextureCreator();
	~TextureCreator();

	std::shared_ptr<sf::Texture> createBlendingCircle(float radius, sf::Color color, int count = 1);
};

