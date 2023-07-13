#include "Apple.h"
#include <cstdlib>
#include <ctime>

Apple::Apple(int height, int width)
{
	char a = '*';
	/*int p = 0;*/

	apple = a;
	/*points = p;*/
	appleRow = rand() % height;
	appleCol = rand() % width;
}

int Apple::getAppleRow()
{
	return appleRow;
}

int Apple::getAppleCol()
{
	return appleCol;
}