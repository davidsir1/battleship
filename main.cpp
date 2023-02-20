#include <iostream>
#include "game.hpp"

int main(){
	
	Game g;

	std::cout << "Reinice o programa caso ele fique em um loop... CTRL-C\n";
	g.OnStart();

	return 0;
}

