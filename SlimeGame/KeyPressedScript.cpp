#include "KeyPressedScript.hpp"

KeyPressedScript::KeyPressedScript(sf::Keyboard::Key key, std::function<void()> func)
    : Script(func)
    , key(key)
{ }

KeyPressedScript::~KeyPressedScript()
{ }

void KeyPressedScript::update()
{
    if (sf::Keyboard::isKeyPressed(key)) {
        execute();
    }
}

void KeyPressedScript::setKey(sf::Keyboard::Key key)
{
    this->key = key;
}

unsigned char KeyPressedScript::getKey()
{
    return key;
}
