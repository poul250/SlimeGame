#include "EntityManager.hpp"

EntityManager::EntityManager()
{ }

EntityManager::EntityManager(std::list<std::shared_ptr<Entity> > entities) : entities(entities)
{ }

EntityManager::~EntityManager()
{ }

void EntityManager::addEntity(std::shared_ptr<Entity>  entity)
{
	entities.push_back(entity);
}

void EntityManager::addEntity(std::list<std::shared_ptr<Entity> > any)
{
	for (std::list<std::shared_ptr<Entity> >::iterator it = any.begin(); it != any.end(); ++it) {
		entities.push_back(*it);
	}
}

void EntityManager::update()
{
	for (std::list<std::shared_ptr<Entity> >::iterator it = entities.begin(); it != entities.end(); ++it) {
		(*it)->update();
	}
	entities.remove_if([&](std::shared_ptr<Entity> entity) {
		return !(entity->isActive());
	});
}

void EntityManager::draw(RenderTarget & target, RenderStates states) const
{
	for (std::shared_ptr<Entity>  ent : entities) {
		target.draw(*ent, states);
	}
}