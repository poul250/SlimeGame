#include "Animation.hpp"

Animation::Animation(std::vector<sf::IntRect> rects, float updPerSec, std::shared_ptr<sf::Texture> texture)
	: updatesCount(0)
	, currRect(0)
	, rects(rects)
	, texture(texture)
{ 
	ticksForUpdate = 60 / updPerSec;
}

Animation::~Animation()
{ }

void Animation::update()
{
	for (updatesCount += 1; updatesCount >= ticksForUpdate; updatesCount -= ticksForUpdate, currRect = (currRect + 1) % rects.size());
}

sf::IntRect Animation::getCurrRect() const
{
	return rects[currRect];
}

std::shared_ptr<sf::Texture> Animation::getTexture() const
{
	return texture;
}

void Animation::setTexture(std::shared_ptr<sf::Texture> texture)
{
	this->texture = texture;
}
