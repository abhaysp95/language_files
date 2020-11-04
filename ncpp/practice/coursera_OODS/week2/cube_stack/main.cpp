#include <iostream>
#include "cube.hpp"

/* every variable and other thing is bydefault is put in stack, and the address
 * of stack work as high to low address */

/* after scope is finished, it's may/may not be used(overridden) by operating system */

uiuc::Cube *createUnitCube();
double *someOtherFunction();

uiuc::Cube *createUnitCube() {
	uiuc::Cube cube;
	cube.setLength(5);
	return &cube;  // address of stack memory associated with local variable cube returned
	// why exactly is this a warning ?
}

int main(int argc, char **argv) {
	uiuc::Cube *c = createUnitCube();
	double *totalVolume = someOtherFunction();
	std::cout << "Total Volume: " << *totalVolume << std::endl;
	double volume = c -> getVolume();
	std::cout << "Volume: " << volume << std::endl;
	double surfaceArea = c -> getSurfaceArea();
	std::cout << "Surface Area: " << surfaceArea << std::endl;
	return 0;
}


// some other function that does something that uses the stack memory
double *someOtherFunction() {
	uiuc::Cube c[100];
	double totalVolume{0.0};

	for (int i = 0; i < 100; ++i) {
		c[i].setLength(i);
		totalVolume += c[i].getVolume();
	}
	return &totalVolume;
}
