#pragma once

#include "point.h"
class Ship
{
private:
	Point body[4];
	char ch;
	int size;

public:
	void init(const Point& head, char ch, int size);
	void move(GameConfig::eKeys direction);
};
