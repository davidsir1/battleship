#include "player.hpp"

void Player::playerAttack(std::array<std::array<int, 10>, 10>& grid, const int x, const int y){
	if(grid[x][y] == 0){
		grid[x][y] = -2;
	}else if(grid[x][y] == 1 || grid[x][y] == 2 || grid[x][y] == 3 || grid[x][y] == 4){
		grid[x][y] = -1;
	}
}

bool Player::isHitTheShip(std::array<std::array<int, 10>, 10> &grid, const int x, const int y){
	return (grid[x][y] == 1 || grid[x][y] == 2 || grid[x][y] == 3 || grid[x][y] == 4) ? true : false;
}

void Player::saveBattles(const int win, const std::string playerName, const std::string player2Name){
	file.open("historybattles.txt", std::ios::out | std::ios::app);

	file << playerName << " VS. " << player2Name << '\n';
	win == 1 ? file << win << std::setw(10) << '0' << '\n' :
			  file << '0' << std::setw(10) << win << '\n';

	file << "\n\n";

	file.close();
}


