#include <iostream>
#include "cube.hpp"

void sendCopy(uiuc::Cube c) {
	// ... logic to send cube(money) to send here
}

void sendCopy1(uiuc::Cube& c) {
	// ... logic to send cube(money) to send here
}

void sendCopy2(uiuc::Cube* c) {
	// ... logic to send cube(money) to send here
}

int main(int argc, char **argv) {
	/** Transfer a cube to another cube by value */
	uiuc::Cube c(10);  // create
	uiuc::Cube myCube = c;  // transfer(copy constructor created a second cube)
	/* but that's not we wanna do */

	std::cout << "----------------" << std::endl;

	uiuc::Cube c1(15);
	uiuc::Cube& myCube1 = c1;  // this one is just another name(reference) to c1

	std::cout << "----------------" << std::endl;

	uiuc::Cube c2(20);  // to create a pointer object you need new
	uiuc::Cube *myCube2 = &c2;  // again, myCube2 is just pointing to c2, no copy

	std::cout << "----------------" << std::endl;

	/* Pass by value/pointer/reference */

	// send the cube to someone
	sendCopy(c);  // sending money, but copy of money will'be created by sendCopy(not what we want)
	std::cout << "----------------" << std::endl;
	sendCopy1(c1);  // sending the alias of this variable, no copy(constructor)
	std::cout << "----------------" << std::endl;
	sendCopy2(&c2);  // no copies, sending direct pointing reference
	std::cout << "----------------" << std::endl;
	uiuc::Cube c3(25);
	c = c3;
	std::cout << "----------------" << std::endl;
	uiuc::Cube &c4 = c3;
	c4 = c1;
	std::cout << "----------------" << std::endl;
	uiuc::Cube *c5 = new uiuc::Cube(30);
	myCube2 = c5;  // this will not use custom assignment operator constructor
	myCube = c5;  // this will
	return 0;
}

/* same way we can return by value/pointer/reference, also keep in mind that:
 * never return a reference to a stack variable created on the stack of current
 * function */
