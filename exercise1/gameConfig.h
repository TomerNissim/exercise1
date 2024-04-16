#ifndef __GAME_CONFIG_H
#define __GAME_CONFIG_H

class GameConfig
{
public:
	enum class eKeys { LEFT = 'a', RIGHT = 'd', UP = 'w', DOWN = 'x',BIGSHIP = 'b', SMALLSHIP = 's', ESC = 27 };
	static constexpr int GAME_WIDTH = 20;
	static constexpr int GAME_HEIGHT = 20;

	static constexpr int MIN_X = 10;
	static constexpr int MIN_Y = 3;

	static constexpr int BIG_SHIP_SIZE = 4;
	static constexpr int SMALL_SHIP_SIZE = 2;

};
#endif