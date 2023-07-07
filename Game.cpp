#include "Game.h"
#include <iostream>
using namespace std;

Game::Game(int h, int w)
{
	height = h;
	width = w;
	snake = Snake({ {0, 0}, {0, 1}, {1, 1}, {1, 2} }, UP);

}

void Game::render()
{
	// Body of snake variable
	auto bList = snake.getBody();
	auto head = snake.head();

	//int borderLength = width + 2;
	vector<vector<char>> matrix = boardMatrix();

	printf("Height: %d\n", height);
	cout << "Width: " << width << endl;

	// Print matrix and border
	// Top of border
	cout << '\n' << UL << string(width, H) << UR << endl;

	// Matrix and side borders
	for (int r = 0; r < height; r++)
	{
		// Left border
		cout << V;

		for (int c = 0; c < width; c++)
		{
			/*for (auto it = bList.begin(); it != bList.end(); it++)
			{
				if (c == std::get<0>(*it) && r == std::get<1>(*it))
				{
					if (c == get<0>(head) && r == get<1>(head))
					{
						cout << 'X';
					}
					
					cout << 'O';
				}
			}*/
			/*auto cIt = *std::find(bList.begin(), bList.end(), c);
			auto rIt = *std::find(bList.begin(), bList.end(), r);*/
			auto t = make_tuple(c, r);

			auto it = find(bList.begin(), bList.end(), t); /*)
				{
					return get<0>(t) == get<0>(item)
						&& get<1>(t) == get<1>(item);
				});*/

			if (it != bList.end())
			{
				if (it == bList.begin())
				{
					cout << 'X';
				}
				else
				{
					cout << 'O';
				}
			}
			else
			{

				cout << matrix[r][c];
			}
		}

		// Right border
		cout << V << endl;

	}

	// Bottom border
	cout << BL << string(width, H) << BR << endl;


}

std::vector<std::vector<char>> Game::boardMatrix()
{
	vector<vector<char>> board(height, vector<char>(width));

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			board[row][col] = ' ';
		}
	}

	return board;
}
