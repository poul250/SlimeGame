#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "UIButton.hpp"

using namespace sf;

class ButtonManager : public Drawable
{
public:
	ButtonManager();
	~ButtonManager();

	void addButton(UIButtonPtr button);
	void removeButton(UIButtonPtr button);

	void update();
protected:
	void draw(RenderTarget& target, RenderStates states) const override;
private:
	std::vector<UIButtonPtr> buttons;
};

