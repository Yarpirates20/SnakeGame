#pragma once
#include <vector>
#include "Snake.h"

const char H = '\xCD';	// Double horizontal
const char V = '\xBA';	// Double vertical
const char UR = '\xBB';	// Upper right corner
const char UL = '\xC9';	// Upper left corner
const char BL = '\xC8';	// Bottom left corner
const char BR = '\xBC';	// Bottom right corner

class Game
{
private:
	int height;
	int width;
	

public:

	Snake snake;

	Game() = default;
	Game(int h, int w);
	void render();
	std::vector<std::vector<char>> boardMatrix();
	int getHeight();
	int getWidth();

};

