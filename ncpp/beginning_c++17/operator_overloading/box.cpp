#include "box.hpp"

Box::Box(double l, double w, double h):
	length{l}, width{w}, height{h} {}

Box::Box(double s):
	length{s}, width{s}, height{s} {}

double Box::volume() const {
	return length * width * height;
}

bool Box::hasSameVolumeAs(const Box &other) const {
	return this->volume() == other.volume();
}

double Box::getLength() const {
	return this->length;
}

double Box::getWidth() const {
	return this->width;
}

double Box::getHeight() const {
	return this->height;
}

bool Box::operator<(const Box &other) const {
	return this->volume() < other.volume();
}

// since the method is inline, it's definition also resied in box.hpp
/* inline bool Box::operator<(double value) const {
	return this->volume() < value;
} */
// ordinary function
/* bool operator<(const Box &first, const Box &second) {
	return first.volume() < second.volume();
} */

// will not work
/* std::ostream& Box::operator<<(std::ostream& stream, const Box& box) {
	stream << "Box(" << std::setw(2) << box.getLength() << ','
		<< std::setw(2) << box.getWidth() << ','
		<< std::setw(2) << box.getHeight() << ')';
	return stream;
} */

// box.hpp contains declaration of this ordinary function
std::ostream& operator<<(std::ostream& stream, const Box& box) {  // works
	stream << "Box(" << std::setw(2) << box.getLength() << ','
		<< std::setw(2) << box.getWidth() << ','
		<< std::setw(2) << box.getHeight() << ')';
	return stream;
}
