#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "StateManager.hpp"
using namespace std;
using namespace sf;

class Game {
public:
    static Game * getGame(int width, int height, int scale, string title);
    void start();
    static void stop();
private:
    Game(int width, int height, int scale, string title);

    void update();
    void draw();

    static bool running;

    static Game *instance;
    RenderWindow window;
    StateManager stateManager;
    RenderStates renderStates;
};
