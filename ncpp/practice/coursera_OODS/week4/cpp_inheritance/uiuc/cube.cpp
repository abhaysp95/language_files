#include <iostream>
#include "cube.hpp"
#include "../shapes.hpp"
#include "HSLAPixel.hpp"

namespace uiuc {
	Shape::Shape() : width_(1) {}
	Shape::Shape(double width) : width_(width) {}
	double Shape::getWidth() const { return width_; }

	Cube::Cube(double width, uiuc::HSLAPixel& color) {
		color_ = color;
	}
	double Cube::getVolume() const {
		return getWidth() * getWidth() * getWidth();
	}
};
