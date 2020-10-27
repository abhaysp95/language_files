#include "cube.hpp"
#include "HSLAPixel.hpp"

namespace uiuc {
	Cube::Cube(double length, uiuc::HSLAPixel color) {
		length_ = length;
		color_ = color;
	}
	double Cube::getLength() const {
		return length_;
	}

	double Cube::getVolume() const {
		return length_ * length_ * length_;
	}

	double Cube::getSurfaceArea() const {
		return 6 * length_ * length_;
	}

	void Cube::setLength(double length) {
		length_ = length;
	}
};
