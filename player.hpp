#ifndef PLAYER_HPP 
#define PLAYER_HPP

#include <fstream>
#include <array>
#include <iomanip>

class Player{
	public:
		void playerAttack(std::array<std::array<int, 10>, 10>& grid, const int x, const int y);
		void saveBattles(const int win, const std::string playerName, const std::string player2Name = "BOB");
		bool isHitTheShip(std::array<std::array<int, 10>, 10>& grid, const int x, const int y);

	private:
		std::fstream file;
};

#endif // !
