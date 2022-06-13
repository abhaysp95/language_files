#include "cube.hpp"

#include <iostream>

Cube::Cube(double aSide): side(aSide) {
	std::cout << "Cube constructor called" << std::endl;
}

double Cube::Volume() {
	return side * side * side;
}

bool Cube::hasLargerVolumeThean(Cube aCube) {
	return Volume() > aCube.Volume();
}

// multiple values can be passed in this initializer list or delegation to
// other copy constructors can be done too
Cube::Cube(const Cube &aCube): Cube{aCube.side}
{}
