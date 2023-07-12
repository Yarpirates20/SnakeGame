#pragma once
#include "Game.h"
class Apple
{

private:
	const char apple = '\x3';
	int points;


public:
	Apple() = default;
	Apple(char a, int p);
	void addToPoints();
	int getPointTotal();
	std::tuple<int, int> setAppleLocation();
};

