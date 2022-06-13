#include "cube.hpp"

#include <iostream>

int main(void) {
	Cube box1 {7.0};
	Cube box2 {3.0};
	if (box1.hasLargerVolumeThean(box2)) {
		std::cout << "box1 larger than box2" << std::endl;
	} else {
		std::cout << "box1 has less than or equal volume to box2" << std::endl;
	}

	std::cout << "Volume of box1: " << box1.Volume() << std::endl;
	/* if (box1.hasLargerVolumeThean(50.0)) {  // processed as box1.hasLargerVolumeThean(cube{50.0})
		std::cout << "box1 has volume greater than 50.0" << std::endl;
	} else {
		std::cout << "box1 has volume less than or equal to 50.0" << std::endl;
	} */  // error because using explicit constructor
}
