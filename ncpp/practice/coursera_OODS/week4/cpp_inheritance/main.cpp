#include <iostream>
#include "uiuc/cube.hpp"

int main(int argc, char **argv) {
	uiuc::Cube c(10, uiuc::HSLAPixel::PURPLE);
	std::cout << "Created a purple cube!" << std::endl;
	return 0;
}
