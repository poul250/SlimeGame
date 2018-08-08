#pragma once
#include <random>
#include <SFML/Graphics.hpp>
#include "Camera.hpp"
#include "Dot.hpp"

class DotsManager : public sf::Drawable {
public:
    DotsManager(Camera * camera, int num = 0);
    ~DotsManager();

    //Sets vector of wind speed
    void setWindSpeed(Vector2f speed);

    //Adding (num) dots in array
    void addDots(size_t num);

    //Removing (num) dots from array or (size of array) dots if size < num
    void removeDots(size_t num);

    //Sets count of dots in array
    void setDotsNum(size_t num);

    //Sets dots color
    void setColor(Color color);

    //Update func
    void update();
	
    //Returns array size
    int getNum() const;

    //Returns wind speed
    Vector2f getWind() const;
protected:
    //Draw dots on RenderTarget
    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
private:
    //Camera, to create dots in it nearby
    Camera * camera;

    //Bounds of Camera
    const int displayShift = 50;

    //wind dir
    Vector2f wind = Vector2f(0.0f, 0.3f);

    //Dots array
    vector<Dot> dots;
};
