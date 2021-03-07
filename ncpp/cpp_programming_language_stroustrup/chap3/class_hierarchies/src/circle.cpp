// cpp file for "circle.hpp"

#include "../inc/circle.hpp"

Circle::Circle(Point p, int rr): _x{p}, _r(rr) {}
Circle::~Circle() {}

Point Circle::center() const { return this->_x; }
void Circle::move(Point to) { this->_x = to; }

void Circle::draw() const {
	// do something here
}

void Circle::rotate(int d) { /** do something */ }