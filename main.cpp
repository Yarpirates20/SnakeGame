#include <iostream>
#include "Game.h"
#include "Snake.h"
using namespace std;

int main()
{
	Game game = Game(10, 20);
	cout << "Enter the following keypresses to move: \n\n";
	cout << "\tUP = W\n"
		<< "\tDOWN = S\n"
		<< "\tLEFT = A\n"
		<< "\tRIGHT = D\n";
	cout << "\nPress ENTER to see the snake move! It's stop motion!\n\n";
	game.render();

	while (true)
	{
		char direction;
		

		cout << "\n\nDirection: ";
		cin >> direction;

		//while (tolower(direction) != 'w' && tolower(direction) != 'a' && tolower(direction) != 's' && tolower(direction) != 'd')
		//{
		//	cout << "\nError: Invalid entry.\n"
		//		<< "Type direction key and press ENTER: ";
		//	cin >> direction;
		//}

		int x = get<0>(game.snake.head());
		int y = get<1>(game.snake.head());
		tuple<int, int> newHead;

		switch (tolower(direction))
		{
		case 'w':
			/*x = (((x - game.getHeight()) - 1) % game.getHeight());*/
			if (game.snake.getDirection() == DOWN)
			{
				break;
			}
			else
			{
				x = 1 + (x - 1 + -1) % game.getHeight();
				newHead = make_tuple(x, y);
				game.snake.setDirection(UP);
				game.snake.takeStep(newHead);
				break;
			}

		case 's':
			/*x = (((x - game.getHeight()) + 1) % game.getHeight());*/
			if (game.snake.getDirection() == UP)
			{
				break;
			} 
			else
			{
				x = 1 + (x - 1 + 1) % game.getHeight();
				//x = ((x + 1) % game.getHeight());
				newHead = make_tuple(x, y);
				game.snake.setDirection(DOWN);
				game.snake.takeStep(newHead);
				break;
			}

		case 'a':
			//y = ((y - 1) % game.getWidth());
			//y = (((y - game.getWidth()) - 1) % game.getWidth());
			if (game.snake.getDirection() == RIGHT)
			{
				break;
			}
			else
			{
				y = 1 + (y - 1 + (-1)) % game.getWidth();
				newHead = make_tuple(x, y);
				game.snake.setDirection(LEFT);
				game.snake.takeStep(newHead);
				break;
			}

		case 'd':
			//y = ((y + 1) % game.getWidth());
			//y = (((game.getWidth() - y) + 1) % game.getWidth());
			if (game.snake.getDirection() == LEFT)
			{
				break;
			}
			else
			{
				y = 1 + (y - 1 + (1)) % game.getWidth();
				newHead = make_tuple(x, y);
				game.snake.setDirection(RIGHT);
				game.snake.takeStep(newHead);
				break;
			}

		default:
			x = 1 + (x - 1 + (get<0>(game.snake.getDirection()))) % game.getHeight();
			x = 1 + (x - 1 + (get<1>(game.snake.getDirection()))) % game.getWidth();
			newHead = make_tuple(x, y);
			game.snake.takeStep(newHead);
			break;
		}

		
		// Copy body to vector for comparison
		vector<tuple<int, int>> snakeVec;

		for (auto it : game.snake.getBody())
		{
			snakeVec.push_back(it);
		}

		for (int i = 0; i < snakeVec.size(); i++)
		{
			if (i != 0)
			{
				if (get<0>(snakeVec[i]) == get<0>(game.snake.head()) && get<1>(snakeVec[i]) == get<1>(game.snake.head()))
				{
					cout << "\nYou've made one wrong move and instantly died. Welcome to real life.\n";
					break;
				}
				else
				{
					cout << "\u001b[2J";
					game.render();
				}
			}

		}



		// ###############################################
		// TODO: Check if each x, y part of tuple, or each tuple, is equal to the first one or any other ones
		// 
		//auto t = make_tuple(x, y);

		//auto it = find(game.snake.getBody().begin(), game.snake.getBody().end(), t);

		//if (it != game.snake.getBody().end())
		//{
		//	if ( *it != game.snake.head())
		//	{
		//		if (*it == newHead)
		//		{
		//			cout << "\nYou made one wrong move and died. Welcome to the real world.\n";
		//			break;
		//		}
		//	}
		//}
		cout << "\u001b[2J";
		game.render();


	}

	return 0;
}