#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class Animation
{
public:
    Animation(std::vector<sf::IntRect> rects, float updPerSec, std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>());
    ~Animation();
	
    void update();
    sf::IntRect getCurrRect() const;

    std::shared_ptr<sf::Texture> getTexture() const;
    void setTexture(std::shared_ptr<sf::Texture> texture);
private:
    std::shared_ptr<sf::Texture> texture;
    std::vector<sf::IntRect> rects;
    int currRect;
    float updatesCount;
    float ticksForUpdate;
};
