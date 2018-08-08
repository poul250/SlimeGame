#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Entity.hpp"
#include "ButtonManager.hpp"
#include "Assets.hpp"

using namespace sf;

class MainMenu : public State
{
public:
    MainMenu();
    ~MainMenu();
    void update() override;

    void enterState() override;
    void leaveState() override;
protected:
    void draw(RenderTarget & target, RenderStates states) const override;
private:
    ButtonManager buttonManager;
    RectangleShape bg;
    Music music;
};
