#include <iostream>
#include "pair.hpp"

int main(int argc, char **argv) {
	Pair p(15, 16);
	Pair q(p);
	Pair *hp = new Pair(23, 42);
	delete hp;
	std::cout << "message printed" << std::endl;
	return 0;
}
