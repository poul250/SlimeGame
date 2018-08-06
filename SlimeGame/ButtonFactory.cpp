#include "ButtonFactory.hpp"

ButtonFactory::ButtonFactory()
{ }

ButtonFactory::~ButtonFactory()
{ }

UIButtonPtr ButtonFactory::create(RectangleShape rect, ButtonFunc func) const {
    return UIButtonPtr(new ColorButton(rect, func));
}
