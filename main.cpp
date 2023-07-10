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

		while (tolower(direction) != 'w' && tolower(direction) != 'a' && tolower(direction) != 's' && tolower(direction) != 'd')
		{
			cout << "\nError: Invalid entry.\n"
				<< "Type direction key and press ENTER: ";
			cin >> direction;
		}

		int x = get<0>(game.snake.head());
		int y = get<1>(game.snake.head());
		tuple<int, int> newHead;

		switch (tolower(direction))
		{
		case 'w':
			x = ((x - 1) % game.getHeight());
			newHead = make_tuple(x,y);
			game.snake.setDirection(UP);
			game.snake.takeStep(newHead);
			break;

		case 's':
			x = ((x + 1) % game.getHeight());
			newHead = make_tuple(x, y);
			game.snake.setDirection(DOWN);
			game.snake.takeStep(newHead);

		case 'a':
			y = ((y - 1) % game.getWidth());
			newHead = make_tuple(x, y);
			game.snake.setDirection(LEFT);
			game.snake.takeStep(newHead);

		case 'd':
			y = ((y + 1) % game.getWidth());
			newHead = make_tuple(x, y);
			game.snake.setDirection(RIGHT);
			game.snake.takeStep(newHead);
		default:
			break;
		}

		cout << "\u001b[2J";

		game.render();
	}

	return 0;
}