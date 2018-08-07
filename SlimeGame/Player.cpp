#include "Player.hpp"
#include "Assets.hpp"

Player::Player()
    : Creature(FloatRect(50, 50, 60, 60))
    , standAnim(Assets::stand, 10, Assets::textures["stand"])
    , leftAnim(Assets::moveLeft, 10)
    , rightAnim(Assets::moveRight, 10)
    , jumpAnim(Assets::jump, 10)
    , curAnimation(&standAnim)
    , jumpForce(13.0f)
    , speed(5.0f)
    , updateFunc(&Player::airUpdate)
{
    setTexture(curAnimation->getTexture().get());
}

Player::~Player()
{ }

void Player::update()
{
    updEntityStates();
    (this->*updateFunc)();
    curAnimation->update();
    setTextureRect(curAnimation->getCurrRect());
}

void Player::onMove(int dir)
{
    vx = dir * speed;
}

void Player::jump()
{
    if (updateFunc == &Player::groundUpdate) {
        updateFunc = &Player::airUpdate;
        vy = -jumpForce;
    }
}

void Player::stand()
{
    updateFunc = &Player::groundUpdate;
    vy = 0;
}

void Player::fall()
{
    updateFunc = &Player::airUpdate;
}

void Player::groundUpdate()
{
    setPosition(getPosition().x + vx, getPosition().y);
    vx = 0;
}

void Player::airUpdate()
{
    vy += Assets::gravity;
    setPosition(getPosition().x + vx, getPosition().y + vy);
    vx = 0;
}