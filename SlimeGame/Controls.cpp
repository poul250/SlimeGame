#include "Controls.hpp"

Controls::Controls(Controlable * controlable)
    : contr (controlable)
{ }

Controls::~Controls()
{ }

void Controls::update()
{
    contr->move(sf::Keyboard::isKeyPressed(sf::Keyboard::D) -
        sf::Keyboard::isKeyPressed(sf::Keyboard::A));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        contr->jump();
}

void Controls::setControlable(Controlable * contr)
{
    this->contr = contr;
}
