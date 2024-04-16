#include "ship.h"


void Ship::init(const Point& head, char ch, int size)
{
	this->ch = ch;
	this->size = size;
	body[0] = head;
	body[0].draw(ch);
	for (int i = 1; i < size; i++)
	{
		body[i] = body[i - 1];
		body[i].move((GameConfig::eKeys)0);
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
