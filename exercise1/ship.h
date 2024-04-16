#pragma once

#include "point.h"
class Ship
{
private:
	Point body[4];
	char ch;
	int size;

public:
	void init(int x, int y, char ch, int size);
	void move(GameConfig::eKeys direction);
	int getSize() { return size; };

};
