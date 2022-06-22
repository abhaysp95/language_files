#include "carton.hpp"                         // For the Carton class

#include <iostream>

int main(void) {
	Carton carton;
	Carton candyCarton {50.0, 30.0, 20.0, "Thin cardboard"};

	std::cout << "carton volume is " << carton.volume() << std::endl;
	std::cout << "candyCarton volume is " << candyCarton.volume() << std::endl;

	return 0;
}

