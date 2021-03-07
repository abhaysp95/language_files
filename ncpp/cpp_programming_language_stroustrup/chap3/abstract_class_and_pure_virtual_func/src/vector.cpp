// cpp file for "vector.hpp"

#include "../inc/vector.hpp"

#include <stdexcept>

//Vector::Vector(int s): _elem(new double[s]), _sz(s) {}

// statement of what is assumed to be true for a class is known as class invariant(or just invariant)

Vector::Vector(std::initializer_list<double> lst): _elem(new double[lst.size()]), _sz(lst.size()) {}

Vector::Vector(int s) {
	if (s < 0) {
		throw std::length_error{"negative size provided"};
	}
	this->_elem = new double[s];
	this->_sz = s;
}

Vector::~Vector() { delete[] this->_elem; }

double& Vector::operator[](int i) const {
	if (i < 0 || i >= this->size()) {
		throw std::out_of_range{"Vector::operator[]"};
	}
	return this->_elem[i];
}

int Vector::size() const { return this->_sz; }