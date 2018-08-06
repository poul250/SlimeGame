#include <iostream>
#include "DotsManager.hpp"

DotsManager::DotsManager(Camera * camera, int num)
    : camera(camera)
{
    const float x = camera->getX(), y = camera->getY();
    const float w = camera->getWidth(), h = camera->getHeight();

    cout << x << " " << y << endl;
    for (int i = 0; i < num; ++i) {
        Dot dot;
        dot.setPosition(x - (w / 2 + displayShift) + rand() % (int(w) + 2 * displayShift),
                        y - (h / 2 + displayShift) + rand() % (int(h) + 2 * displayShift));
        dots.push_back(dot);
    }
}

DotsManager::~DotsManager()
{ }


void DotsManager::setWindSpeed(Vector2f speed)
{
    wind = speed;
}

void DotsManager::addDots(size_t num)
{
    const float x = camera->getX(), y = camera->getY();
    const float w = camera->getWidth(), h = camera->getHeight();
    for (size_t i = 0; i < num; ++i) {
        Dot dot;
        dot.setFillColor(Color::White);
        dot.setPosition(x - (w / 2 + displayShift) + rand() % (int(w) + 2 * displayShift),
                        y - (h / 2 + displayShift) + rand() % (int(h) + 2 * displayShift));
        dots.push_back(dot);
    }
}

void DotsManager::removeDots(size_t num)
{
    for (size_t i = 0; (i < num) && (dots.size() > 0); ++i) {
        dots.pop_back();
    }
}

void DotsManager::setDotsNum(size_t num)
{
    const float x = camera->getX(), y = camera->getY();
    const float w = camera->getWidth(), h = camera->getHeight();
	
    while (dots.size() < num) {
        Dot dot;
        dot.setPosition(x - (w / 2 + displayShift) + rand() % (int(w) + 2 * displayShift),
                        y - (h / 2 + displayShift) + rand() % (int(h) + 2 * displayShift));
        dots.push_back(dot);
    }

    while (dots.size() > num) {
        dots.pop_back();
    }
}

void DotsManager::setColor(Color color)
{
    for (auto dot : dots) {
        dot.setColor(color);
    }
}

void DotsManager::update()
{
    const float x = camera->getX(), y = camera->getY();
    const float w = camera->getWidth(), h = camera->getHeight();

    for (Dot & dot : dots) {
        dot.update();
        dot.move(wind);
        auto pos = dot.getPosition();
        if (pos.x < x - (w / 2 + 2 * displayShift) || pos.x > x + (w / 2 + 2 * displayShift) ||
            pos.y < y - (h / 2 + 2 * displayShift) || pos.y > y + (h / 2 + 2 * displayShift) ||
            dot.isDead())
        {
            dot.reset();
            dot.setPosition(x - (w / 2 + displayShift) + rand() % (int(w) + 2 * displayShift),
                            y - (h / 2 + displayShift) + rand() % (int(h) + 2 * displayShift));
        }
    }
}

int DotsManager::getNum() const
{
    return dots.size();
}

Vector2f DotsManager::getWind() const
{
    return wind;
}

void DotsManager::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    for (auto dot : dots) {
        target.draw(dot, states);
    }
}
