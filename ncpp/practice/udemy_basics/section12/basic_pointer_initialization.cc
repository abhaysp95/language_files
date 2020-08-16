// demonstration of basic pointer initialization

#include <iostream>

int main() {
	int *p;  // un-initialized pointer
	std::cout << p << std::endl;
	std::cout << *p << std::endl;
	std::cout << &p << std::endl;
	std::cout << sizeof(p) << std::endl;
	p = 0;
	std::cout << p << std::endl;
	// std::cout << *p << std::endl;
	std::cout << &p << std::endl;
	std::cout << sizeof(p) << std::endl;
	return 0;
}
