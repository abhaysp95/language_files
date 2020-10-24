#include "cube.hpp"
#include <iostream>

namespace uiuc {
	Cube::Cube() {
		length_ = 1;
		std::cout << "Custom with no param Constructor invoked" << std::endl;
	}
	Cube::Cube(double length) {
		length_ = length;
		std::cout << "Custom Constructor invoked" << std::endl;
	}
	Cube::Cube(const Cube& obj) {
		length_ = obj.length_;  // automatic copy constructor does exactly this(copying)
		std::cout << "Copy Constructor invoked" << std::endl;
	}
	Cube& Cube::operator=(const Cube& obj) {
		length_ = obj.length_;
		std::cout << "copy assignment operator invoked" << std::endl;
		return *this;
	}
	double Cube::getVolume() {
		return length_ * length_ * length_;
	}

	double Cube::getSurfaceArea() {
		return 6 * length_ * length_;
	}

	void Cube::setLength(double length) {
		length_ = length;
	}
};
