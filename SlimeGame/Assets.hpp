#pragma once
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Assets {
public:
	static void init(int width, int height, int scale, RenderWindow * window);
	static std::string getString(std::string);
	static int getWidth();
	static int getHeight();
	static int getScale();
	static RenderWindow * getWindow();

	static std::map<std::string, std::string> strings;
	static std::map<string, std::shared_ptr<Texture> > textures;
	static std::vector<IntRect> stand;
	static std::vector<IntRect> moveRight;
	static std::vector<IntRect> moveLeft;
	static std::vector<IntRect> jump;

	static float gravity;
	static float fps;
private:
	static int width;
	static int height;
	static int scale;
	static RenderWindow *window;
};
