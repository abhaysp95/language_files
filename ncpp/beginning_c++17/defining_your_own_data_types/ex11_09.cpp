#include "cuboid.hpp"

#include <iostream>
#include <memory>

int main(void) {
	Cuboid c1 {2.2, 1.1, 0.5};
	Cuboid c2;
	std::unique_ptr<Cuboid> c3 = std::make_unique<Cuboid>(16.0, 20.0, 8.0);  // or use auto

	std::cout << "Volume and surface area: \n";

	std::cout << c1.Volume() << " " << surfaceArea(c1) << std::endl;
	std::cout << c2.Volume() << " " << surfaceArea(c2) << std::endl;
	std::cout << c3->Volume() << " " << surfaceArea(*c3) << std::endl;

	// std::cout << "Object count is " << Cuboid::objectCount << std::endl;  // objectCount is private, this is just showcasing the usage

	return 0;
}

double surfaceArea(const Cuboid &aCuboid) {
	return 2.0 * (aCuboid.length * aCuboid.width +
			aCuboid.width * aCuboid.height +
			aCuboid.height * aCuboid.length);
}
