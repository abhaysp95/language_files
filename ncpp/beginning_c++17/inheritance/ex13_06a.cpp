#include "cerealpack.hpp"

#include <iostream>

int main(void) {
	CerealPack cornflakes {8.0, 3.0, 10.0, "Cornflakes"};
	std::cout << "cornflakes volume is " << cornflakes.Carton::volume() << std::endl
		<< "cornflakes weight is " << cornflakes.Contents::getWeight() << std::endl;


	// another way
	std::cout << "cornflakes volume is " << static_cast<Carton&>(cornflakes).volume() << std::endl
		<< "cornflakes weight is " << static_cast<Contents&>(cornflakes).getWeight() << std::endl;
	return 0;
}

// only try to qualify function names in main() (or for user classes) when you
// can't change the classes itself

// we cast reference and not class type to avoid creation of new object
