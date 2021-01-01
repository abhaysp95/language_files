// cpp file for "b.hpp"

#include "../inc/b.hpp"
#include "../inc/a.hpp"

#include <iostream>

auto B = A();

auto E = A;  // dynamic initliazed

int print_value() {
	std::cout << B << std::endl;
	std::cout << E << std::endl;
	return EXIT_SUCCESS;
}

// write here