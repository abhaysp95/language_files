#include <iostream>
#include "cube.hpp"

namespace uiuc {
	Cube::Cube() { length_ = 1; }
	Cube::Cube(unsigned l) { length_ = l; }
	void Cube::setLength(const unsigned l) { length_ = l; }
	int Cube::getLength() { return length_; }
	void Cube::getVolume() {
		std::cout << "Volume: " << length_ * length_ * length_ << std::endl;
	}
	void Cube::getVolume(const unsigned l) {
		setLength(l);
		getVolume();
	}
};
