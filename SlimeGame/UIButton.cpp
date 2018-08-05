#include "UIButton.hpp"


UIButton::UIButton(ButtonFunc func) : func(func)
{ }

UIButton::~UIButton()
{ }

void UIButton::setFunc(ButtonFunc func)
{
	this->func = func;
}

ButtonFunc UIButton::getFunc() const
{
	return ButtonFunc();
}

void UIButton::execute()
{
	func();
}