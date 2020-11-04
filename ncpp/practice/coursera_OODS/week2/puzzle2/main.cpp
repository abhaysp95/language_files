#include <iostream>

int main(int argc, char **argv) {
	int *x = new int;
	int &y = *x; // y is referencing to the address of heap pointed by x
	// meaning, that new int address is now called/referred as y
	y = 7;
	std::cout << "*x: " << *x << std::endl;
	std::cout << "x: "  << x  << std::endl;
	std::cout << "&x: " << &x << std::endl;

	//std::cout << "*y: " << *y << std::endl;
	std::cout << "y: "  << y  << std::endl;
	std::cout << "&y: " << &y << std::endl;

	/* address stored in *x is the same of address of &y */

	const int size = 5;
	int *arr = new int[size];  // array is created sequencially inside heap
	for (int i = 0; i < size; ++i) {
		*(arr + i) = i + 3;
	}
	for (int i = 0; i < size; ++i) {
		std::cout << x + i << std::endl;  // gradually increasing address(acc. to type)
	}
	delete[] arr;  // delete already know bounds/size of arr


	/* TODO: check returning the address of array(stack one), just as done in
	 * C, from a function or local scope and see if it gives warning */
	return 0;
}
