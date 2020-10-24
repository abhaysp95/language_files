#include <iostream>
#include "cube.hpp"

/* every variable and other thing is bydefault is put in stack, and the address
 * of stack work as high to low address */

/* after scope is finished, it's may/may not be used(overridden) by operating system */

uiuc::Cube foo(uiuc::Cube cube) {
	std::cout << "Reached foo" << std::endl;
	return cube;
}

uiuc::Cube* bar(uiuc::Cube *cube) {
	std::cout << "Reached bar" << std::endl;
	return cube;
}

int main(int argc, char **argv) {
	/* cube with default constructor */
	uiuc::Cube *c = new uiuc::Cube(10);  // try providing length in constructor
	std::cout << "c volume: " << c -> getVolume() << std::endl;
	uiuc::Cube c2(5);
	std::cout << "c2 volume: " << c2.getVolume() << std::endl;
	bar(c);  // copy constructor not invoked
	std::cout << "-------------------" << std::endl;
	foo(c2);  // copy constructor invoked
	std::cout << "-------------------" << std::endl;
	uiuc::Cube *c3 = bar(c);
	std::cout << "-------------------" << std::endl;
	uiuc::Cube c4 = foo(c2);
	std::cout << "-------------------" << std::endl;
	uiuc::Cube *c5 = c3;
	std::cout << "-------------------" << std::endl;
	uiuc::Cube c6 = c4;
	std::cout << "-------------------" << std::endl;
	uiuc::Cube c7 = *c5;  // that's basically dereferencing and then copying that instance to c7
	std::cout << "-------------------" << std::endl;
	uiuc::Cube *c8 = new uiuc::Cube(*c5);  // same here
	std::cout << "-------------------" << std::endl;
	uiuc::Cube c9;
	uiuc::Cube c10;
	c9 = c10;  // no copy constructor called, since c9 and c10 are already created by default constructor
	// but copy assignment operator invoked
	std::cout << "-------------------" << std::endl;
	uiuc::Cube *c11 = new uiuc::Cube;
	uiuc::Cube *c12 = new uiuc::Cube;
	*c11 = *c12;  // copy assignment operator invoked
	return 0;
}

/* Any custom constructor provided(whether automatic or not) prevents automatic
 * default constructor to be provided from C++ */

/* Checkout copy constructor and move constructor as well */

/* Automatic copy constructor is provided to us if we don't give it explicitly,
 * automatic copy constructor copies the contents of all member variables
 * A copy constructo should/have be:
 * -> a class constructor
 * -> should have exactly one argument
 *   -> the argument must be a constant reference of the same type as of the class
 */

/* Often copy constructor are invoked automatically
 * -> Passing an object as parameter(by value)
 * -> Passing an object from function a function(by value)
 * -> intializing a new object
 */


/* Functionality/Work is same to copy constructor of assignment operator, but
 * time invoked are different, this one is invoked when object already exists
 * and assignment operator is used
 * Copy Assignment Operator:
 * -> public member function of the class
 * -> has the name operator=
 * -> has return value of reference of class type
 * -> has exactly one argument
 *   -> the argument must be a const reference of the class' type
 */
