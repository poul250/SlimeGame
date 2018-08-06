#pragma once
#include <functional>
#include <memory>
#include <SFML/Graphics.hpp>

typedef std::function<void()> ButtonFunc;

class UIButton : public sf::Drawable
{
public:
    UIButton(ButtonFunc);
    virtual ~UIButton();
    void setFunc(ButtonFunc);
    ButtonFunc getFunc() const;
    virtual void update() = 0;
protected:
    void execute();
private:
    ButtonFunc func;
};

typedef std::shared_ptr<UIButton> UIButtonPtr;
