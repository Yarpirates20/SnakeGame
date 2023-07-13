#pragma once
#include "Game.h"
class Apple
{

private:
	char apple;
	int appleRow;
	int appleCol;


public:
	Apple() = default;
	Apple(int h, int w);
	int getAppleRow();
	int getAppleCol();
	
	
};

