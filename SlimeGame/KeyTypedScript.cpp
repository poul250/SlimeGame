#include "KeyTypedScript.hpp"

KeyTypedScript::KeyTypedScript(sf::Keyboard::Key key, std::function<void()> func)
    : Script(func)
    , key(key)
    , updFunc(&KeyTypedScript::NotPressed)
{ }

KeyTypedScript::~KeyTypedScript()
{ }

void KeyTypedScript::update()
{
    (this->*updFunc)();
}

void KeyTypedScript::Pressed()
{
    if (Keyboard::isKeyPressed(key)) {
        updFunc = &KeyTypedScript::Pressed;
    }
}

void KeyTypedScript::NotPressed()
{
    if (!Keyboard::isKeyPressed(key)) {
        updFunc = &KeyTypedScript::NotPressed;
        execute();
    }
}
