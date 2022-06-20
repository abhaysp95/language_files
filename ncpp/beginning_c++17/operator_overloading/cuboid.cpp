#include "cuboid.hpp"

#include <iostream>
#include <iomanip>

Cuboid::Cuboid(double aSide): Cuboid{aSide, aSide, aSide} {
	std::cout << "Cube constructor called" << std::endl;
}

Cuboid::Cuboid(double l, double w, double h): length{l}, width{w}, height{h}
{}

double Cuboid::volume() const {
	return this->length * this->width * this->height;
}

bool Cuboid::hasLargerVolumeThean(Cuboid aCube) {
	return volume() > aCube.volume();
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

double Cuboid::getLength() const {
	return this->length;
}

double Cuboid::getWidth() const {
	return this->width;
}

double Cuboid::getHeight() const {
	return this->height;
}

void Cuboid::printVolume() const {
	std::cout << "Volume of box: " << this->volume() << std::endl;
	std::cout << "printVolume() has been called " << ++this->count << " times" << std::endl;
	// updating count is possible even though method is const is because of mutable keyword
}

size_t Cuboid::getObjectByCount() const {
	return this->objectCount;
}

int Cuboid::compare(const Cuboid &cuboid) const {
	if (this->volume() < cuboid.volume()) return -1;
	if (this->volume() == cuboid.volume()) return 0;
	return +1;
}

/* void Cuboid::listCuboid() const {
	std::cout << " Box(" << std::setw(2) << this->length << ','
		<< std::setw(2) << this->width << ','
		<< std::setw(2) << this->height << ')';
} */
