#pragma once
#include "Game.h"
class Apple
{

private:
	char apple;
	int points;
	int appleRow;
	int appleCol;


public:
	Apple();
	void addToPoints();
	int getPointTotal();
	void setAppleLocation(int h, int w);
	int getAppleRow();
	int getAppleCol();
	bool isEaten();
};

