// cpp file for "vector_container.hpp"

#include "../inc/vector_container.hpp"

Vector_Container::Vector_Container(int s): _v(s) {}

double Vector_Container::operator[](int i) const { return this->_v[i]; }

int Vector_Container::size() const { return this->_v.size(); }

Vector_Container::~Vector_Container() {}
