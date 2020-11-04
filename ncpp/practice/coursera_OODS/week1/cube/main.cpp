#include <iostream>
#include "cube.hpp"

int main(int argc, char **argv) {
	uiuc::Cube c;
	c.setLength(3.48);
	double volume = c.getVolume();
	std::cout << "Volume: " << volume << " unit cube." << std::endl;
	double surfaceArea = c.getSurfaceArea();
	std::cout << "Surface Area: " << surfaceArea << " unit sq." << std::endl;
	return 0;
}
