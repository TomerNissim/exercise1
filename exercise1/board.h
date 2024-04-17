
#pragma once

#include "gameConfig.h"

class Board {

	char* board[GameConfig::GAME_HEIGHT * GameConfig::GAME_WIDTH];


	public:

		void init();
		bool add(int x , int y, char symbol);
		void erase(int x , int y);
		GameConfig::eGameObj checkPoint(int x, int y);
		bool isBlockCanMove(Point p, GameConfig::eKeys direction, int size);
		bool isBlockCanMove(Point p, Point p2, GameConfig::eKeys direction, int size);
		void moveBlock(Point p, GameConfig::eKeys direction);
};