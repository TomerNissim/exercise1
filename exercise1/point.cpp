#include "point.h"
#include "gameConfig.h"
#include "general.h"

#include <iostream>
#include <Windows.h>
using namespace std;

void Point::init(int x, int y)
{
	this->x = x;
	this->y = y;
	diff_x = 1;
	diff_y = 0;
}
void Point::draw(char ch)
{
	gotoxy(x + GameConfig::MIN_X - 1, y + GameConfig::MIN_Y - 1);
	cout << ch;
}
void Point::move(GameConfig::eKeys key)
{
	switch (key)
	{
	case GameConfig::eKeys::LEFT:
		diff_x = -1;
		diff_y = 0;
		break;
	case GameConfig::eKeys::RIGHT:
		diff_x = 1;
		diff_y = 0;
		break;
	case GameConfig::eKeys::UP:
		diff_x = 0;
		diff_y = -1;
		break;
	case GameConfig::eKeys::DOWN:
		diff_x = 0;
		diff_y = 1;
		break;
	case GameConfig::eKeys::SMALLSHIP:
		diff_x = 0;
		diff_y = 0;
		break;
	case GameConfig::eKeys::BIGSHIP:
		diff_x = 0;
		diff_y = 0;
		break;
	}


	x += diff_x;
	if (x > GameConfig::GAME_WIDTH)
		x = 1;
	else if (x == 0)
		x = GameConfig::GAME_WIDTH;

	y += diff_y;
	if (y > GameConfig::GAME_HEIGHT)
		y = 1;
	else if (y == 0)
		y = GameConfig::GAME_HEIGHT;
}
