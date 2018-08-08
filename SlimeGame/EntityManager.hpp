#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "EnvManager.hpp"
class EntityManager : public sf::Drawable
{
public:
    EntityManager();
    EntityManager(std::list<EntityPtr> entities);
    ~EntityManager();

    void addEntity(std::shared_ptr<Entity> entity);
    void addEntity(std::list<std::shared_ptr<Entity> >);
    void update();
protected:
    void draw(RenderTarget &target, RenderStates states) const override;
private:
    std::list<std::shared_ptr<Entity> > entities;
    EnvManager env;
};
