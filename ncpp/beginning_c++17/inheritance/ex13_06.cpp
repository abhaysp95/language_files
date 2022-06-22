#include "cerealpack.hpp"

#include <iostream>

int main(void) {
	CerealPack cornflakes {8.0, 3.0, 10.0, "Cornflakes"};
	std::cout << "cornflakes volume is " << cornflakes.volume() << std::endl
		<< "cornflakes weight is " << cornflakes.getWeight() << std::endl;
	return 0;
}

// will not compile
//
// comment out
		/* using Carton::volume;
		using Contents::getWeight; */
// to see the problem
