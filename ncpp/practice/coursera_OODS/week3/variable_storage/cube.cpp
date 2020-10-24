#include "cube.hpp"
#include <iostream>

namespace uiuc {
	Cube::Cube(double length) {
		length_ = length;
		std::cout << "Created $" << getVolume() << std::endl;
	}
	Cube::Cube(const Cube& obj) {
		length_ = obj.length_;
		std::cout << "Created $" << getVolume() << " via copy" << std::endl;
	}
	Cube& Cube::operator=(const Cube& obj) {
		length_ = obj.length_;
		std::cout << "Transformed $" << getVolume() << " -> $" << obj.getVolume() << std::endl;
		return *this;
	}
	Cube* Cube::operator=(const Cube* obj) {
		length_ = obj -> length_;
		std::cout << "Transformed $" << getVolume() << " -> $" << obj -> getVolume() << std::endl;
		return this;
	}
	double Cube::getVolume() const{
		// const due to obj in the operator= is using const Cube, and you can't
		// call non-const function from const object
		return length_ * length_ * length_;
	}

	double Cube::getSurfaceArea() {
		return 6 * length_ * length_;
	}

	void Cube::setLength(double length) {
		length_ = length;
	}
};
