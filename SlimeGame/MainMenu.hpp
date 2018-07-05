#pragma once
#include <string>
#include "State.hpp"
#include "Entity.hpp"

using namespace std;
using namespace sf;

class MenuBackGround : public Drawable 
{
public:
	MenuBackGround();
	~MenuBackGround();
	void update();
protected:
	void draw(RenderTarget& target, RenderStates states) const override;
private:
	RectangleShape rect;
	Font font;
	Text text;
};

class MainMenu : public State 
{
public:
	MainMenu(State *prev);
	~MainMenu();
	void update() override;
protected:
	virtual void draw(RenderTarget & target, RenderStates states) const override;
private:
	MenuBackGround menuBG;
};
