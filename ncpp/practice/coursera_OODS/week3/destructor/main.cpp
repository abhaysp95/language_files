#include <iostream>
#include "cube.hpp"

double cubeOnStack() {
	uiuc::Cube c1(10);
	return c1.getVolume();
}

double cubeOnHeap() {
	uiuc::Cube *c1 = new uiuc::Cube(15);
	uiuc::Cube *c2 = new uiuc::Cube;
	delete c1;
	return c2 -> getVolume();
}

int main(int argc, char **argv) {
	double vol1 = cubeOnStack();
	std::cout << "vol1: " << vol1 << std::endl;
	double vol2 = cubeOnHeap();
	std::cout << "vol2: " << vol2 << std::endl;
	double vol3 = cubeOnStack();
	std::cout << "vol3: " << vol3 << std::endl;
	return 0;
}

/* A destructor should never be called directly, instead it's automactically
 * called when memory is being reclaimed by the system
 * -> If the object is on stack, when the function returns
 * -> If object is on heap, when 'delete' is used
 * It's used to have a custom behavior at the end of lifetime of the object
 * Destructor is necessary when object allocates an external resource that
 * must be closed or freed when the object is destroyed, e.g., heap/shared
 * memory, file opening
 */
