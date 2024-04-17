#include "ship.h"
#include "board.h"


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
//up: i = 0, 1  -- - both
//right : 1 -- - both, 3 -- - big
//down : 2, 3 big, 0, 1 small
//left : 0 -- - both, 2 big

GameConfig::eGameObj Ship::checkMove() {
	Board board;
	Point p = body[0], p2;
	GameConfig::eGameObj output = GameConfig::eGameObj::EMPTY;
	switch (direction)
	{
	case GameConfig::eKeys::LEFT:
		p.move(GameConfig::eKeys::LEFT);
		if (size > 2) {
			p2 = p;
			p2.move(GameConfig::eKeys::DOWN);
			return checkInBoard(p, p2);

		}
		else {
			return checkInBoard(p);
		}
	case GameConfig::eKeys::RIGHT:
		p.move(GameConfig::eKeys::RIGHT);
		p.move(GameConfig::eKeys::RIGHT);
		if (size > 2) {
			p2 = p;
			p2.move(GameConfig::eKeys::DOWN);
			return checkInBoard(p, p2);

		}
		else {
			return checkInBoard(p);
		}
	case GameConfig::eKeys::UP:
		p.move(GameConfig::eKeys::UP);
		p2 = p;
		p2.move(GameConfig::eKeys::RIGHT);
		return checkInBoard(p, p2);

	case GameConfig::eKeys::DOWN:
		p.move(GameConfig::eKeys::DOWN);
		p2 = p;
		p2.move(GameConfig::eKeys::RIGHT);
		if (size > 2) {
			p.move(GameConfig::eKeys::DOWN);
			p2.move(GameConfig::eKeys::DOWN);
			return checkInBoard(p, p2);
		}
		else {
			return checkInBoard(p, p2);;
		}
	}
	return GameConfig::eGameObj::EMPTY;
}

GameConfig::eGameObj Ship::checkInBoard(Point p , Point p2) {


	GameConfig::eGameObj output1 = board.checkPoint(p.getX(), p.getY());
	GameConfig::eGameObj output2 = board.checkPoint(p2.getX(), p2.getY());

	if (output1 == GameConfig::eGameObj::WALL || output2 == GameConfig::eGameObj::WALL) return GameConfig::eGameObj::WALL;
	if (output1 == GameConfig::eGameObj::EMPTY && output2 == GameConfig::eGameObj::EMPTY) return GameConfig::eGameObj::EMPTY;
	if (output1 == GameConfig::eGameObj::SMALLBLOCK || output1 == GameConfig::eGameObj::BIGBLOCK) {
		if (board.isBlockCanMove(p, direction, size)) {

			return output1;
		}
		else {
			return GameConfig::eGameObj::WALL;
		}
	}
	if (output2 == GameConfig::eGameObj::SMALLBLOCK || output2 == GameConfig::eGameObj::BIGBLOCK) {
		if (board.isBlockCanMove(p2, direction, size)) {

			return output2;
		}
		else {
			return GameConfig::eGameObj::WALL;
		}
	}

}

GameConfig::eGameObj Ship::checkInBoard(Point p) {


	GameConfig::eGameObj output1 = board.checkPoint(p.getX(), p.getY());
	if (output1 == GameConfig::eGameObj::SMALLBLOCK || output1 == GameConfig::eGameObj::BIGBLOCK) {
		if (board.isBlockCanMove(p, direction, size)) {

			return output1;
		}
		else {
			return GameConfig::eGameObj::WALL;
		}
	}
	return output1;

}


