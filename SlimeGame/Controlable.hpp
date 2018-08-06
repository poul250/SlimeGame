#pragma once
class Controlable {
public:
    Controlable();
    virtual ~Controlable();
	
    virtual void onMove(int dir) = 0;
    virtual void jump() = 0;
};