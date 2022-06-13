#include "cuboid.hpp"

#include <iostream>

Cuboid::Cuboid(double aSide): Cuboid{aSide, aSide, aSide} {
	std::cout << "Cube constructor called" << std::endl;
}

Cuboid::Cuboid(double l, double w, double h): length{l}, width{w}, height{h}
{}

double Cuboid::Volume() {
	return this->length * this->width * this->height;
}

bool Cuboid::hasLargerVolumeThean(Cuboid aCube) {
	return Volume() > aCube.Volume();
}

// multiple values can be passed in this initializer list or delegation to
// other copy constructors can be done too
Cuboid::Cuboid(const Cuboid &aCube): Cuboid{aCube.length, aCube.width, aCube.height}
{}

Cuboid& Cuboid::setLength(double l) {
	this->length = l;
	return *this;  // returing reference
				   // for method chaning you can return pointers too
}

Cuboid& Cuboid::setWidth(double w) {
	this->width = w;
	return *this;
}

Cuboid& Cuboid::setHeight(double h) {
	this->height = h;
	return *this;
}

