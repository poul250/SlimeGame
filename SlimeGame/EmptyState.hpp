#pragma once
#include "State.hpp"

class EmptyState : public State {
public:
    EmptyState();

    void update() override;
protected:
    void draw(RenderTarget &target, RenderStates state) const override;
private:
    sf::RectangleShape rect;
};
