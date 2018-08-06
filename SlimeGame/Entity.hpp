#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

using namespace sf;

class Entity : public RectangleShape {
public:
    Entity(FloatRect rect = FloatRect(0, 0, 0, 0));
    virtual ~Entity();
    virtual void update() = 0;

    bool isActive() const;
    virtual bool interactsWithEnv();
protected:
    bool active = true;
};

typedef std::shared_ptr<Entity> EntityPtr;