#pragma once
#include "Creature.hpp"
#include "Animation.hpp"
#include "Controlable.hpp"
class Player : public Creature, public Controlable {
public:
    Player();
    ~Player();
    void update() override;

    void move(int dir) override;
    void jump() override;

    FloatRect getRect() const override;
protected:
    void draw(RenderTarget &target, RenderStates states) const override;
private:
    typedef void(Player::*UpdateFunc)();

    void groundUpdate();
    void airUpdate();

    Animation standAnim, leftAnim, rightAnim, jumpAnim;
    Animation *curAnimation;
    RectangleShape rect;
    UpdateFunc updateFunc;
    float speed;
    float jumpForce;
    bool jumpFlag;
};

