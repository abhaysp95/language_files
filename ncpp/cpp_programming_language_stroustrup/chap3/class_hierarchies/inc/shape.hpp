// header file

#ifndef _GUARD_SHAPE_HPP_
#define _GUARD_SHAPE_HPP_

#include "../inc/point.hpp"

class Shape {
	public:
		virtual Point center() const = 0;
		virtual void move(Point to) = 0;

		// draw on current canvas
		virtual void draw() const = 0;
		virtual void rotate(int angle) = 0;

		virtual ~Shape() = 0;
};

#endif