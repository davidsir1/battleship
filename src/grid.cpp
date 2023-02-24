#include "grid.hpp"

void Grid::fillGrid(std::array<std::array<int, width>, height>& grid){
	for(int i = 0; i<height; ++i){
		for(int j = 0; j<width; ++j){
			grid[i][j] = 0;
		}
	}
}

void Grid::printGrid(std::array<std::array<int, width>, height>& grid, std::array<std::array<int, width>, height>& grid2){
	std::cout << std::setw(4);
	for(int i = 65; i<75; i++){
    	std::cout << char(i) << ' ';
	}
	std::cout << std::setw(6);
	for(int i = 65; i<75; i++){
		std::cout << char(i) << ' ';
	}
	std::cout << '\n';
	for(int i = 0; i<height-1; i++){
	    std::cout << i+1 << " |";
	    for(int j = 0; j<width; j++){
	        std::cout << printBlock(grid[i][j]) << ' ';
	    }
	    std::cout << "  ";
	    std::cout << i+1 << " |";
	    for(int j = 0; j<width; j++){
	        std::cout << printBlock(grid2[i][j], 0) << ' ';
	    }
	    std::cout << '\n';
	}
	std::cout << "10|";
	for(int j = 0; j<width; j++){
	    std::cout << printBlock(grid[9][j]) << ' ';
	}
	std::cout << "  ";
	std::cout << "10|";
	for(int j = 0; j<width; j++){
		std::cout << printBlock(grid2[9][j], 0) << ' ';
	}
	std::cout << '\n';

}

char Grid::printBlock(const int block, bool show){
	// Water = ~ = 126; Ships = # = 35; Missed = X = 88; Hit = * = 42
	switch(block){
		case 0:
			return '~';
			break;
		case 1:
		case 2:
		case 3:
		case 4:
			return show ? '#' : '~';
			break;
		case -2:
			return 'X';
			break;
		case -1:
			return '*';
			break;
	}
}

void Grid::setShipsPosition(std::array<std::array<int, width>, height>& grid, int size){
	int countShips = 0;
	while(countShips < TOTAL_SHIPS){
		const bool side = randomInteger(0, 1);
		const int posX = randomInteger(0, height - (side ? size : 0));	
		const int posY = randomInteger(0, width - (side ? 0 : size));

		if(verifyPosition(grid, posX, posY, size, side)){
			for(int i = 0; i<size; ++i){
				grid[side ? posX : posX + i][side ? posY + i : posY] = size;
			}
			countShips++;
		}
	}
}

void Grid::positionShips(std::array<std::array<int, width>, height> &grid){
	for(int size : SHIP_SIZE){
		setShipsPosition(grid, size);
		TOTAL_SHIPS--;
	}
	TOTAL_SHIPS = 4;
}

bool Grid::verifyPosition(std::array<std::array<int, width>, height> &grid, const int x, const int y, int size, bool side){
	if((side ? y+size : x+size) > (side ? width : height)){
		return false;
	}
	bool isFree = true;
	for(int i = 0; i<size; ++i){
		if((side ? checkBorders(grid,x,y+i) : checkBorders(grid, x+i,y)) || (x+i < 0 || x+i >= height || y+i < 0 || y+i >= width)){
			isFree = false;
			break;
		}
	}
	return isFree;
}

bool Grid::checkBorders(std::array<std::array<int, width>, height>& grid, const int x, const int y){
	// verifica os espaçoes adjacentes
	if(grid[x][y] != 0){
		return true;
	}
	for(int i = -1; i<=1; ++i){
		for(int j = -1; j<=1; ++j){
			int row = x+i;
			int col = y+j;
			if(row >= 0 && row < height && col >= 0 && col < width){
				if(grid[row][col] != 0){
					return true;
				}
			}
		}
	}
	
   	return false;
}

int Grid::randomInteger(int min, int max){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(min, max);

	return dist(gen);
}

int Grid::countCellsGrid(std::array<std::array<int, width>, height>& grid){
	int count = 0;
	for(int i = 0; i<height; i++){
		for(int j = 0; j<width; j++){
			if(grid[i][j] == 1 || grid[i][j] == 2 || grid[i][j] == 3 ||grid[i][j] == 4){
				count++;	
			}
		}
	}
	return count;
}
