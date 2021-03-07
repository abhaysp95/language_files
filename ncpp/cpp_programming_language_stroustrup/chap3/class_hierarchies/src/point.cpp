// cpp file for "shape.hpp"

#include "../inc/point.hpp"

Point::Point(int x, int y): _x{x}, _y{y} {}
Point::Point(): _x{}, _y{} {}

int Point::getX() const { return this->_x; }
int Point::getY() const { return this->_y; }

void Point::setX(int x) { this->_x = x; }
void Point::setY(int y) { this->_y = y; }