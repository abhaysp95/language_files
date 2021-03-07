// main file

#include <iostream>

#include "../inc/vector.hpp"

void f(Vector& v) {
	try {
		Vector d1 = {1, 2, 3, 4, 5};  // uses std::initializer_list
		Vector d2 = {1.2, 2.3, 3.4, 4.5};
		// trying to access value from v which is out of range for demo
		v[v.size()] = 7;
	}
	catch (std::out_of_range) {  // exception handling(catch)
		std::cout << "v out of range" << std::endl;
	}
}

void test() {
	try {
		Vector v(-27);
	}
	catch (std::length_error) {
		// handle negative size
	}
	// if operator can't find new memory to allocate, it throws bad_alloc
	catch (std::bad_alloc) {
		// handle memory exhaustion
	}
}

int main(int argc, char **argv) {
	/* code here */
	return 0;
}