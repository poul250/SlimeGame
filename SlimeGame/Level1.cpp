#include <iostream>
#include "Level1.hpp"

Level1::Level1()
    : bg(Vector2f(823, 180))
    , camera(FloatRect(0, 0, Assets::getWidth(), Assets::getHeight()),
             Assets::getWindow(), Assets::getScale())
    , player1(std::make_shared<Player>())
    , player2(std::make_shared<Player>())
    , controls(player1.get())
    , dots(&camera, 10)
{
    player1->setScale(Vector2f(1.5f, 1.5f));

    camera.followEntity(player1.get());
    camera.setOffset(0, /*-118*/ -80);
    camera.floatCamera(true);

    entManager.addEntity(player1);
    entManager.addEntity(player2);
}

Level1::~Level1()
{ }

void Level1::update()
{
    if (Keyboard::isKeyPressed(Keyboard::O)) {
        controls.setControlable(player1.get());
        camera.moveTo(player1.get());
    }
    if (Keyboard::isKeyPressed(Keyboard::P)) {
        controls.setControlable(player2.get());
        camera.moveTo(player2.get());
    }

    controls.update();
    entManager.update();
    camera.update();
    dots.update();
}

void Level1::init(int & progress)
{
    bgTexture = make_shared<Texture>();
    if (!bgTexture->loadFromFile("background_1.png")) {
        std::cout << "Error reading \"background_1.png\" texture" << std::endl;
        exit(-1);
    }
    bg.setTexture(bgTexture.get());
    bg.setSize(Vector2f(1646.f, 360));
    progress = 100;
}

void Level1::draw(RenderTarget & target, RenderStates states) const
{
    target.draw(bg, states);
    target.draw(entManager, states);
    target.draw(dots, states);
}
