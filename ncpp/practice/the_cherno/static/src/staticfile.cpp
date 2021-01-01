// cpp file for "staticfile.hpp"

#include "../inc/staticfile.hpp"

#include <iostream>

static int this_is_a_global_variable = 15;

void print_static_variable () {
	std::cout << this_is_static_variable << std::endl;
	std::cout << this_is_a_global_variable << std::endl;
}