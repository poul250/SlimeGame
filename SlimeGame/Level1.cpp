#include "Level1.hpp"

Level1::Level1() 
    : bg(Vector2f(Assets::getWidth(), Assets::getHeight()))
    , camera(FloatRect(0, 0, Assets::getWidth(), Assets::getHeight()),
             Assets::getWindow(), Assets::getScale())
    , player1(std::make_shared<Player>())
    , player2(std::make_shared<Player>())
    , controls(player1.get())
    , dots(&camera, 10)
{
    bg.setTexture(Assets::textures["menuBG"].get());

    camera.followEntity(player1.get());
    camera.setOffset(0, -80); 

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
    progress = 100;
}

void Level1::draw(RenderTarget & target, RenderStates states) const
{
    target.draw(bg, states);
    target.draw(entManager, states);
    target.draw(dots, states);
}
