#pragma once

#include "point.h"
#include "board.h"

class Ship
{
private:
	Point body[4];
	char ch;
	int size;
	GameConfig::eKeys direction;
	Board& board;
	GameConfig::eGameObj checkInBoard(Point p);
	GameConfig::eGameObj checkInBoard(Point p, Point p2);


public:
	Ship();
	void init(int x, int y, char ch, int size);
	void move(GameConfig::eKeys direction);
	int getSize() { return size; };
	GameConfig::eKeys getDirection() { return direction; };
	void setDirection(GameConfig::eKeys dir) { direction = dir; };

	GameConfig::eGameObj checkMove();

};
