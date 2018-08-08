#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

using namespace sf;

class EnvManager {
public:
    EnvManager();
    ~EnvManager();

    void interactWithEnv(std::shared_ptr<Entity> entity) const;
private:
    //Zone, where entities can exist
    FloatRect gz;
    std::vector<FloatRect> objects;
    const float SHIFT = 0.01;
};
