#include <iostream>
#include "LoadScreen.hpp"
#include "MainMenu.hpp"
#include "ButtonFactory.hpp"
#include "EmptyState.hpp"
#include "Game.hpp"
#include "Level1.hpp"

MainMenu::MainMenu()
    : bg(Vector2f(640, 360))
    , rect(Vector2f(640, 360))
    , updateFunc(&MainMenu::CommonUpdate)
{
    bg.setPosition(0, 0);
    bg.setTexture(Assets::textures["menuBG"].get());
    bg.setTextureRect(IntRect(0, 0, 640, 360));

    rect.setPosition(0, 0);
    rect.setFillColor(Color(0, 0, 0, 0));

    RectangleShape button1(Vector2f(100, 50));
    RectangleShape button2 = button1, button3 = button1;
    ButtonFactory factory;
    button1.setPosition(200, 30);
    button2.setPosition(200, 100);
    button3.setPosition(200, 170);
    buttonManager.addButton(factory.create(button1, [&]() {
        step = 30;
        updateFunc = &MainMenu::LeaveStateUpdate;
    }));

    buttonManager.addButton(factory.create(button2, [&]() {
        addState(std::make_shared<EmptyState>());
    }));
	
    buttonManager.addButton(factory.create(button3, [&]() {
        Game::stop();
    }));

    if (!music.openFromFile("vtoroyogg.ogg")) {
        exit(-1);
    }
}

MainMenu::~MainMenu() 
{ }

void MainMenu::update()
{
    (this->*updateFunc)();
}

void MainMenu::lostFocus()
{
    if (updateFunc == &MainMenu::CommonUpdate) {
        updateFunc = &MainMenu::NotFocused;
    }
}

void MainMenu::gainedFocus()
{
    if (updateFunc == &MainMenu::NotFocused) {
        updateFunc = &MainMenu::CommonUpdate;
    }
}

void MainMenu::enterState()
{
    updateFunc = &MainMenu::CommonUpdate;
    music.play();
}

void MainMenu::draw(RenderTarget & target, RenderStates states) const
{
    target.draw(bg, states);
    target.draw(buttonManager, states);
    target.draw(rect, states);
}

void MainMenu::CommonUpdate()
{
    buttonManager.update();
}

void MainMenu::NotFocused()
{ }

void MainMenu::LeaveStateUpdate()
{
    if (step-- > 0) {
        music.setVolume(music.getVolume() * 0.8);
        rect.setFillColor(Color(0, 0, 0, Uint8(255 * (1 - float(step) / 30))));
    }
    else {
        music.stop();
        replaceState(std::make_shared<LoadScreen>(std::make_shared<Level1>()));
    }
}
