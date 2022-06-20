#include "volume.hpp"

#include <iostream>

int main(void) {
	Volume volume;
	std::cout << volume(10, 20, 30) << std::endl;  // functor usage

	Cuboid cuboid{2, 3, 4};
	std::cout << volume(cuboid) << std::endl;

	return 0;
}
