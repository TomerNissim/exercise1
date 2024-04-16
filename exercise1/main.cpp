#include <conio.h> // for kbhit+getch
#include <iostream>
#include <Windows.h> // for Sleep and colors

using namespace std;

#include "general.h"
#include "gameConfig.h"
#include "point.h"
#include "ship.h"

void drawBorderSomewhere();

void shipTester();

int main() {
	drawBorderSomewhere();

	shipTester();

}

void shipTester()
{
	drawBorderSomewhere();
	int x = GameConfig::MIN_X, y = GameConfig::MIN_Y;
	Ship s;
	Point head;
	head.init(2, 2);
	s.init(head, '#', 2);



	int keyPressed = 0; 
	while (true)
	{
		
		if (_kbhit())
		{
			keyPressed = _getch();
			if (keyPressed == (int)GameConfig::eKeys::ESC) {
				break;
			}
		}
		s.move((GameConfig::eKeys)keyPressed);
		Sleep(500);
	}

	}

void drawBorderSomewhere()
{
	for (int col = GameConfig::MIN_X; col < GameConfig::GAME_WIDTH + GameConfig::MIN_X; col++)
	{
		gotoxy(col, GameConfig::MIN_Y - 1);
		cout << "-";

		gotoxy(col, GameConfig::GAME_HEIGHT + GameConfig::MIN_Y);
		cout << "-";
	}

	for (int row = GameConfig::MIN_Y - 1; row <= GameConfig::GAME_HEIGHT + GameConfig::MIN_Y; row++)
	{
		gotoxy(GameConfig::MIN_X - 1, row);
		cout << "|";

		gotoxy(GameConfig::GAME_WIDTH + GameConfig::MIN_X, row);
		cout << "|";
	}
}