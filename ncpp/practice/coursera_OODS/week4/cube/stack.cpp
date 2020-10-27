#include <iostream>
#include <exception>
#include "stack.hpp"

void Stack::push_back(const uiuc::Cube& cube) {
	// Ensure that we don't push a cube on top of smaller cube
	if (size() > 0 && cube.getLength() > peekTop().getLength()) {
		std::cerr << "A smaller cube can't be placed on top of larger cube." << std::endl;
		std::cerr << "  Tried to add Cube(length = " << cube.getLength() << ")" << std::endl;
		std::cerr << "  Current stack: " << *this << std::endl;

		throw std::runtime_error("A smaller cube cannot be placed on top of a larger cube.");
	}
	cubes_.push_back(cube);
}

uiuc::Cube Stack::removeTop() {
	uiuc::Cube cube = peekTop();
	cubes_.pop_back();
	return cube;
}

uiuc::Cube& Stack::peekTop() {
	return cubes_[cubes_.size() - 1];
}

unsigned Stack::size() const {
	return cubes_.size();
}

std::ostream& operator<<(std::ostream& os, const Stack& stack) {
	for (unsigned i = 0; i < stack.size(); ++i) {
		os << stack.cubes_[i].getLength() << " ";
	}
	os << std::endl;
	return os;
}
