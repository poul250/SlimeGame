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
    jumpFlag = true;
}

void Player::groundUpdate()
{
    if (jumpFlag) {
        vy = -jumpForce;
        updateFunc = &Player::airUpdate;
    }

    setPosition(getPosition().x + vx, getPosition().y + vy);
    vx = 0;
}

void Player::airUpdate()
{
    vy += Assets::gravity;

    if (getGlobalBounds().top + getGlobalBounds().height + vy >= 296) {
        updateFunc = &Player::groundUpdate;
        setPosition(getPosition().x + vx, 232);
        jumpFlag = false;
        vy = 0;
    } else {
        setPosition(getPosition().x + vx, getPosition().y + vy);
    }
    vx = 0;
}