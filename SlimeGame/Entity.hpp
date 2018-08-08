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

    virtual void stand();
    virtual void fall();
    FloatRect getPrevGlobalBounds() const;
protected:
    //Neñessary to call in the beginning of void update()
    void updEntityStates();

    bool active = true;
private:
    FloatRect prevGlobalBounds;
};

typedef std::shared_ptr<Entity> EntityPtr;
