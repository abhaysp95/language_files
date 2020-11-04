#include <iostream>
#include "cube.hpp"

/* every variable and other thing is bydefault is put in stack, and the address
 * of stack work as high to low address */

/* after scope is finished, it's may/may not be used(overridden) by operating system */

uiuc::Cube *createUnitCube();
double *someOtherFunction();

uiuc::Cube *createUnitCube() {
	uiuc::Cube *cube = new uiuc::Cube;
	cube -> setLength(5);  // this is similar to (*cube).setLength(5);
	return cube;
}

int main(int argc, char **argv) {
	uiuc::Cube *c = createUnitCube();
	double *totalVolume = someOtherFunction();  // pointing to stack memory down the road
	std::cout << "Total Volume: " << *totalVolume << std::endl;
	double volume = c -> getVolume();
	std::cout << "Volume c: " << volume << std::endl;
	double surfaceArea = c -> getSurfaceArea();
	std::cout << "Surface Area c: " << surfaceArea << std::endl;
	uiuc::Cube *c1 = c;
	std::cout << "Volume c1: " << c1 -> getVolume() << std::endl;
	std::cout << "Surface Area c1: " << c1 -> getSurfaceArea() << std::endl;
	//std::cout << "Address in c: " << c << std::cout;  // what's the way to print
	//std::cout << "Address in c1: " << c1 << std::cout;

	/* address stored in c and c1 is the same from the heap, so c and c1(where
	 * c have slightly higher address than c1 in stack) are pointing to same
	 * memory in heap */
	delete c;
	c = nullptr;
	delete c1;  // double free deprecated, core dumped
	/* it's because content of this heap memory is already deleted with 'delete
	 * c' and we're deleting it again(something maybe which should not be
	 * deleted) */
	c1 = nullptr;
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
	// address of stack memory associated with local variable cube returned
	// why exactly is this a warning ?
}
