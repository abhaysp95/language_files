// main file

#include <iostream>
#include <iomanip>

int main(int argc, char **argv) {
	std::cout << std::setw(20);
	std::cout << "hello";
	std::streamsize prev_width = std::cout.width(10);
	std::cout << "Hello" << std::endl;
	std::cout.width(prev_width);
	return 0;
}