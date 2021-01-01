// main file

#include <iostream>
#include "../inc/b.hpp"

// within a single compilation unit, static variables are initialized in the
// same order as they are defined in the source(this is called ordered dynamic
// initialization). across compilation units, however, the order is undefined,
// you don't know if a static variable defined in a.cpp will be defined
// initialized before or after one in b.cpp

// this turns into a very serious issue if the initiazation of a variable in
// a.cpp depends on another one defined in b.cpp. this is called "static
// initialization order fiasco"

int main(int argc, char **argv) {
	std::cout << print_value() << std::endl;
	return 0;
}