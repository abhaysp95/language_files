// main file

#include <iostream>

#include "../inc/vector.hpp"
#include "../inc/container.hpp"

void use(Container& c) {
	const int size = c.size();
	for (int i = 0; i < size; ++i) {
		std::cout << c[i] << "\n";
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	/* code here */
	return 0;
}