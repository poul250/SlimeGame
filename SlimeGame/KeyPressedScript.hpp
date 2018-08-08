#pragma once
#include <SFML/Graphics.hpp>
#include "Script.hpp"

class KeyPressedScript : public Script {
public:
    KeyPressedScript(sf::Keyboard::Key key, std::function<void()> func);
    ~KeyPressedScript();

    void update() override;

    void setKey(sf::Keyboard::Key key);
    unsigned char getKey();
private:
    sf::Keyboard::Key key;
};
