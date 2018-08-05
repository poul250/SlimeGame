#include "Script.hpp"

Script::Script(std::function<void()> func)
	: func(func)
	, executed(false)
	, repeatable(false)
{ }

Script::~Script()
{ }

void Script::setRepeatable(bool repeat)
{
	repeatable = repeat;
	if (repeat) {
		executed = false;
	}
}

bool Script::isRepeatable() const
{
	return repeatable;
}

void Script::execute()
{
	if (!executed) {
		func();
		if (!repeatable) {
			executed = true;
		}
	}
}
