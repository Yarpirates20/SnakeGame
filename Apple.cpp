#include "Apple.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Apple::Apple(int height, int width)
{
	//char a = '*';
	/*int p = 0;*/

	//apple = a;
	/*points = p;*/
	appleRow = std::rand() % height;
	appleCol = std::rand() % width;
	
}

int Apple::getAppleRow()
{
	return appleRow;
}

int Apple::getAppleCol()
{
	return appleCol;
}