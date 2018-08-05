#pragma once
#include <SFML/Graphics.hpp>
#include "Controlable.hpp"
class Controls {
public:
	Controls(Controlable * controlable);
	virtual ~Controls();

	void update();
	void setControlable(Controlable * contr);
private:
	Controlable * contr;
};

