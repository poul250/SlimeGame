#pragma once
#include "UIButton.hpp"
#include "ColorButton.hpp"
class ButtonFactory
{
public:
	ButtonFactory();
	~ButtonFactory();
	UIButtonPtr create(RectangleShape rect, ButtonFunc func = [&]() {}) const;
};

