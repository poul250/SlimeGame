#include "ColorButton.hpp"
#include "Assets.hpp"

ColorButton::ColorButton(RectangleShape rect, ButtonFunc onClick)
	: UIButton(onClick)
	, rect(rect)
{
	updateFunc = &ColorButton::notActive;
	drawFunc = &ColorButton::notActiveDraw;
}

ColorButton::~ColorButton()
{ }

void ColorButton::update()
{
	(this->*updateFunc)();
}

void ColorButton::draw(RenderTarget & target, RenderStates states) const
{
	(this->*drawFunc)(target, states);
}

bool ColorButton::mouseInRect() const
{
	auto pos = rect.getPosition();
	int scale = Assets::getScale();
	auto size = rect.getSize();
	auto point = Mouse::getPosition(*Assets::getWindow());
	return point.x >= pos.x * scale && point.x <= pos.x * scale + size.x * scale &&
		point.y >= pos.y * scale && point.y <= pos.y * scale + size.y * scale;
}

//Update states

void ColorButton::notActive()
{
	rect.setFillColor(Color::Green);
	if (!Mouse::isButtonPressed(Mouse::Button::Left) && mouseInRect()) {
		updateFunc = &ColorButton::active;
		drawFunc = &ColorButton::activeDraw;
	}
}

void ColorButton::active()
{
	rect.setFillColor(Color::Blue);
	if (!mouseInRect()) {
		updateFunc = &ColorButton::notActive;
	} else if (Mouse::isButtonPressed(Mouse::Button::Left)) {
		updateFunc = &ColorButton::pressed;
	}
}

void ColorButton::pressed()
{
	rect.setFillColor(Color::Red);
	Vector2i pos = Mouse::getPosition();
	if (!mouseInRect()) {
		updateFunc = &ColorButton::notActive;
	} else if (!Mouse::isButtonPressed(Mouse::Button::Left)) {
		updateFunc = &ColorButton::notActive;
		execute();
	}
}

// Draw states
void ColorButton::notActiveDraw(RenderTarget &target, RenderStates states) const
{
	target.draw(rect, states);
}

void ColorButton::activeDraw(RenderTarget &target, RenderStates states) const
{
	target.draw(rect, states);
}

void ColorButton::pressedDraw(RenderTarget &target, RenderStates states) const
{
	target.draw(rect, states);
}