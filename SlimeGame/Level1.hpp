#pragma once
#include <memory>
#include <random>
#include "Camera.hpp"
#include "Assets.hpp"
#include "State.hpp"
#include "EntityManager.hpp"
#include "Player.hpp"
#include "Controls.hpp"
#include "TextureCreator.hpp"
#include "DotsManager.hpp"
class Level1 : public State
{
public:
    Level1();
    ~Level1();
    void update() override;
    void init(int & progress) override;
protected:
    void draw(RenderTarget & target, RenderStates states) const override;
private:
    RectangleShape bg;
    EntityManager entManager;

    std::shared_ptr<Player> player1, player2;
    Controls controls;
    Camera camera;
    DotsManager dots;
};