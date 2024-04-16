#include "ship.h"


void Ship::init(int x, int y, char ch, int size)
{
	this->ch = ch;
	this->size = size;
	Point point;
	for (int i = 0; i < size; i++)
	{
		point.init(x + (int(i % 2)), y + (int)(i / 2));
		body[i] = point;
		body[i].draw(ch);
	}
}
void Ship::move(GameConfig::eKeys direction)
{
	for (int i = size - 1; i >= 0; i--)
	{ 
		body[i].draw(' ');
		body[i].move(direction);
	}

	for (int i = size - 1; i >= 0; i--)
	{
		body[i].draw(ch);
	}
}
