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
	, rect(Vector2f(64, 64))
	, speed(5.0f)
	, updateFunc(&Player::airUpdate)
{ 
	rect.setPosition(20, 10);
	rect.setTexture(curAnimation->getTexture().get());
	vx = 10;
	vy = 10;
}

Player::~Player()
{ }

void Player::update()
{
	(this->*updateFunc)();
	curAnimation->update();
	rect.setTextureRect(curAnimation->getCurrRect());
}

void Player::move(int dir)
{
	vx = dir * speed;
}

void Player::jump()
{
	jumpFlag = true;
}

void Player::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(rect, states);
}

void Player::groundUpdate()
{
	if (jumpFlag) {
		vy = -jumpForce;
		updateFunc = &Player::airUpdate;
	}

	rect.setPosition(rect.getPosition().x + vx, rect.getPosition().y + vy);
	vx = 0;
}

void Player::airUpdate()
{	
	vy += Assets::gravity;

	if (rect.getGlobalBounds().top + rect.getGlobalBounds().height + vy >= 296) {
		updateFunc = &Player::groundUpdate;
		rect.setPosition(rect.getPosition().x + vx, 232);
		jumpFlag = false;
		vy = 0;
	} else {
		rect.setPosition(rect.getPosition().x + vx, rect.getPosition().y + vy);
	}
	vx = 0;
}

FloatRect Player::getRect() const
{
	return rect.getGlobalBounds();
}
