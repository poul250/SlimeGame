#pragma once
#include <SFML/Graphics.hpp>
#include <random>
class Dot : public sf::RectangleShape {
public:
    Dot(sf::Color color = sf::Color(255, 255, 255));
    ~Dot();
	
    void reset();
    void update();

    bool isDead() const;
    void setMaxSpeed(float speed);
    void setColor(sf::Color color);
private:
    void updateColor();

    sf::Color color;

    float maxSpeed = 0.1f;
    const int MAX_ALPHA = 150;
    const int LIFE_LIMIT = 180;
    int maxLifeTime;
    int lifeTime;
    bool dead = false;
    sf::Vector2f speed;
};

