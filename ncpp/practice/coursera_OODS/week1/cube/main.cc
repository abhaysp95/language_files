#include <iostream>
#include "cube.h"

int main() {
	Cube cb;

	cb.setLength(3.42);
	double cubeVolume = cb.getVolume();
	double cubeSurfaceArea = cb.getSurfaceArea();

	std::cout << "Cube's volume is: " << cubeVolume << std::endl;
	std::cout << "Cube's surface area is: " << cubeSurfaceArea << std::endl;
	return 0;
}
