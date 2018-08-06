#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "UIButton.hpp"

using namespace sf;

class ColorButton : public UIButton
{
public:
    ColorButton(RectangleShape rect, ButtonFunc onClick);
    virtual ~ColorButton();
    virtual void update() override;
protected:
    virtual void draw(RenderTarget & target, RenderStates states) const override;
private:
    typedef void(ColorButton::*UpdateFunc)();
    typedef void(ColorButton::*DrawFunc)(RenderTarget&, RenderStates) const;

    bool mouseInRect() const;

    void notActive();
    void active();
    void pressed();

    void notActiveDraw(RenderTarget&, RenderStates) const;
    void activeDraw(RenderTarget&, RenderStates) const;
    void pressedDraw(RenderTarget&, RenderStates) const;
	
    RectangleShape rect;

    UpdateFunc updateFunc;
    DrawFunc drawFunc;
};

