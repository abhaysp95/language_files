// main file

#include <iostream>
#include "../inc/staticfile.hpp"

extern int this_is_a_global_variable;

void print_static_variable2() {
	std::cout << this_is_static_variable << std::endl;
	if (this_is_a_global_variable) {
		std::cout << this_is_a_global_variable << std::endl;
	}
	else {
		std::cout << "this_is_a_global_variable not found" << std::endl;
	}
}

int main(int argc, char **argv) {
	print_static_variable();
	print_static_variable2();
	return 0;
}


/** extern is looking for the variable in another file, and if a variable or
 * function is given static it's like private in single translation unint */