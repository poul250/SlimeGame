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

    void lostFocus() override;
    void gainedFocus() override;

    void enterState() override;
protected:
    void draw(RenderTarget & target, RenderStates states) const override;
private:
    typedef void (MainMenu::*UpdateFunc)();

    void CommonUpdate();
    void NotFocused();
    void LeaveStateUpdate();

    UpdateFunc updateFunc;
    ButtonManager buttonManager;
    RectangleShape bg;
    Music music;

    RectangleShape rect;
    int step = 0;
};
