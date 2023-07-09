#pragma once
#include <iostream>
#include <tuple>
#include <vector>
#include <list>
using namespace std;

const std::tuple<int, int> UP = make_tuple(0, 1);
const std::tuple<int, int> DOWN = make_tuple(0, -1);
const std::tuple<int, int> LEFT = make_tuple(-1, 0);
const std::tuple<int, int> RIGHT = make_tuple(1, 0);

class Snake
{
private:
	/*std::tuple<int, int> body;
	std::tuple<int, int> directions;*/

	std::list<std::tuple<int, int>> body;
	std::tuple<int, int> direction;

public:
	Snake() = default;
	Snake(std::list<std::tuple<int, int>> bodySegment, std::tuple<int, int> moveDirection);
	std::list<std::tuple<int, int>> getBody();
	std::list<std::tuple<int, int>> takeStep(/*std::list<std::tuple<int, int>>bodyVec,*/ std::tuple<int, int> dir);
	std::tuple<int, int> setDirection(std::tuple<int, int> dir);
	std::tuple<int, int> head(/*std::list<std::tuple<int,int>> bList*/);
	//int getXcoord()
};

