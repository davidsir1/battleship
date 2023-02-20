#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "player.hpp"
#include "grid.hpp"

class Game : public Grid{
	public:
		Game();
		~Game(){ delete p; }

		int OnStart();

	private:
		std::array<std::array<int, width>, height> gridPlayer, gridPlayer2;
		int win = 0, x = 0, y = 0, cellsP1, cellsP2; 
		Player* p;
};

#endif
