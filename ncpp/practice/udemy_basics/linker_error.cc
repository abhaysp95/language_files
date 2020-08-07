// show linker error

#include <iostream>

extern int x;

int main() {
	std::cout << "Showing linker Error" << std::endl;
	std::cout << x << std::endl;
	return 0;
}
