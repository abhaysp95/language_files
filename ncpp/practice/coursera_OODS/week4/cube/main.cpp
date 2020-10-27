#include "game.hpp"
#include <iostream>

int main(int argc, char **argv) {
	Game g;
	std::cout << "Initial game state: " << std::endl;
	std::cout << g << std::endl;

	g.solve();

	std::cout << "Final game state: " << std::endl;
	std::cout << g << std::endl;
	return 0;
}
