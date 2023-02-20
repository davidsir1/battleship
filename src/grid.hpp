#ifndef GRID_HPP
#define GRID_HPP

#include <array>
#include <iostream>
#include <random>
#include <iomanip>

const int height = 10;
const int width = 10;

class Grid{
	public:
		void fillGrid(std::array<std::array<int, width>, height>& grid);
		void printGrid(std::array<std::array<int, width>, height>& grid, std::array<std::array<int, width>, height>& grid2);
		bool verifyPosition(std::array<std::array<int, width>, height>& grid, const int x, const int y, int size, bool side);
		bool checkBorders(std::array<std::array<int, width>, height>& grid, const int x, const int y);
		void setShipsPosition(std::array<std::array<int, width>, height>& grid, int size);
		void positionShips(std::array<std::array<int, width>, height>& grid);
		char printBlock(const int block, bool show = 1);
		int countCellsGrid(std::array<std::array<int, width>, height>& grid);
		int randomInteger(int min, int max);

	private:
		std::array<int, 4> SHIP_SIZE = { 1, 2, 3 ,4 };
		int TOTAL_SHIPS = 4;
		int x, y;
};

#endif // !GRID_HPP
