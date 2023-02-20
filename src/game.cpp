#include "game.hpp"

int Game::OnStart(){	

	int playerTurn = 1;

	while(!win){
		std::system("clear");
		printGrid(gridPlayer, gridPlayer2);

		switch(playerTurn) {
			case 1:
				std::cout << "Vez do Jogador 1\n";
				std::cout << "Faça o ataque (Linha, Coluna): ";
				std::cin >> x >> y;
				if((x > 0 && x < height) && (y > 0 && y < width)){
					p->playerAttack(gridPlayer2, x-1, y-1);
					if(p->isHitTheShip(gridPlayer2, x-1, y-1)){
						std::cout << "Jogador 1 acertou um barco\n";
						cellsP2--;
					}else{
						std::cout << "Jogador 1 acertou na água\n";
						playerTurn++;
					}
				}
				break;
			case 2:
				std::cout << "Vez do Jogador 2\n";
				x = randomInteger(0, 9); y = randomInteger(0, 9);
				if((x > 0 && x < height) && (y > 0 && y < width)){
					p->playerAttack(gridPlayer, x-1, y-1);
					if(p->isHitTheShip(gridPlayer, x-1, y-1)){
						std::cout << "Jogador 2 acertou um barco\n";
						cellsP1--;
					}else{
						std::cout << "Jogador 2 acertou na água\n";
						playerTurn--;
					}
				}
				sleep(2);
				break;
		}

		if(cellsP1 == 0){ 
			win = 1;
		}else if(cellsP2 == 0){ 
			win = -1;
		}
	}

	return win;
}

Game::Game(){
	p = new Player;
	fillGrid(gridPlayer);
	fillGrid(gridPlayer2);
	positionShips(gridPlayer);
	positionShips(gridPlayer2);
	cellsP1 = countCellsGrid(gridPlayer);
	cellsP2 = countCellsGrid(gridPlayer2);
}
