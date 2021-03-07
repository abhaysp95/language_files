// main file

#include <iostream>

#include "../inc/complex_util.hpp"

void f(Complex z) {
	Complex a{2.3};
	Complex b{1/3};
	//Complex c{-a};
	//Complex c = a + z;
	Complex c{a + z * Complex{1, 2.3}};
	std::cout << c << std::endl;
	if (a != b) {
		std::cout << "a not equal to b" << std::endl;
	}

	Complex* d = new Complex(2.3);
	Complex* f{d + c};
	//Complex* e = new Complex(5.6, 6.5);
	std::cout << f << std::endl;
}

int main(int argc, char **argv) {
	f(Complex{4, 6});
	return 0;
}