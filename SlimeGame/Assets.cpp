#include "Assets.hpp"

std::map<std::string, std::string> Assets::strings;
std::map<string, std::shared_ptr<Texture> > Assets::textures;
std::vector<IntRect> Assets::stand;
std::vector<IntRect> Assets::moveRight;
std::vector<IntRect> Assets::moveLeft;
std::vector<IntRect> Assets::jump;
RenderWindow * Assets::window;
float Assets::gravity;
float Assets::fps;
int Assets::width;
int Assets::height;
int Assets::scale;

void Assets::init(int width, int height, int scale, RenderWindow * window) 
{
	Assets::width = width;
	Assets::height = height;
	Assets::scale = scale;
	Assets::window = window;
	Assets::gravity = 1.0f;
	Assets::fps = 60.0f;

	stand = {
		IntRect(0, 0, 64, 64),
		IntRect(64, 0, 64, 64),
		IntRect(128, 0, 64, 64),
		IntRect(192, 0, 64, 64)
	};

	textures["stand"] = std::make_shared<Texture>();
	textures["menuBG"] = std::make_shared<Texture>();
	if (!textures["stand"]->loadFromFile("gotovo.png") ||
		!textures["menuBG"]->loadFromFile("main_menu.png")) 
	{
		exit(-1);
	}
}

int Assets::getWidth()
{
	return width;
}

int Assets::getHeight()
{
	return height;
}

int Assets::getScale()
{
	return scale;
}

RenderWindow * Assets::getWindow()
{
	return window;
}

std::string Assets::getString(std::string str) 
{
	return strings[str];
}