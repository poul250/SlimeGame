#pragma once
#include "Creature.hpp"
#include "Animation.hpp"
#include "Controlable.hpp"
class Player : public Creature, public Controlable {
public:
    Player();
    ~Player();
    void update() override;

    void onMove(int dir) override;
    void jump() override;
private:
    typedef void(Player::*UpdateFunc)();

    void groundUpdate();
    void airUpdate();

    Animation standAnim, leftAnim, rightAnim, jumpAnim;
    Animation *curAnimation;
    UpdateFunc updateFunc;
    float speed;
    float jumpForce;
    bool jumpFlag;
};