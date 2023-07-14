#include "Snake.h"
using namespace std;

Snake::Snake(list<tuple<int, int>> initSegment, tuple<int, int> initDirection)
{
	body = initSegment;
	direction = initDirection;
	/*body = make_tuple(initBodyX, initBodyY);
	cout << "Body X: " << get<0>(body) << "\tBody Y: " << get<1>(body) << endl;*/
}

std::list<std::tuple<int, int>> Snake::getBody()
{
	return body;
}

// Return vector after adding coordinates and direction
// Use vec.push_back(position) to add position to bac
std::list<std::tuple<int, int>> Snake::takeStep(/*std::list<std::tuple<int, int>>bodyVec,*/ tuple<int,int> position)
{
	body.push_front(position);
	body.pop_back();
	return body;
}

std::tuple<int, int> Snake::setDirection(std::tuple<int, int> dir)
{
	direction = dir;
	return direction;
}

std::tuple<int, int> Snake::getDirection()
{
	return direction;
}

std::tuple<int, int> Snake::head(/*list<tuple<int,int>> bList*/)
{

	return body.front();
	//return bList.front();
}

void Snake::addSegment()
{
	int x = get<0>(body.back()) + get<0>(getDirection());
	int y = get<1>(body.back()) + get<1>(getDirection());

	tuple<int,int> segment = make_tuple(x, y);

	body.push_back(segment);
}
