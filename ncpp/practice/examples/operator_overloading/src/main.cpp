#include <iostream>
#include "../inc/fracutil.hpp"

int main(int argc, char **argv) {
	Fraction x(2, 3);
	Fraction y(6, -2);

	std::cout << x << std::endl;
	std::cout << y << std::endl;

	std::cin >> y;
	std::cout << y << std::endl;
	Fraction z = x + y;
	std::cout << x << " + " << y << " = " << z << std::endl;
	return 0;
}
