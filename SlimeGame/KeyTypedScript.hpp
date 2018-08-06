#pragma once
#include <SFML/Window/Keyboard.hpp>
#include "Script.hpp"

using sf::Keyboard;

class KeyTypedScript :
    public Script {
public:
    KeyTypedScript(Keyboard::Key key, std::function<void()> func);
    ~KeyTypedScript();

    void update() override;
private:
    typedef void(KeyTypedScript::*UpdFunc)();

    void Pressed();
    void NotPressed();

    UpdFunc updFunc;

    sf::Keyboard::Key key;
};

