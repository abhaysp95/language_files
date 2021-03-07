// header file

#ifndef _GUARD_CIRCLE_HPP_
#define _GUARD_CIRCLE_HPP_

#include "../inc/shape.hpp"

/** Circle class will have its own vtable, cause Shape is abstract class and Circle inheriting */

class Circle: public Shape {
	public:
		Circle(Point p, int rr);  // constructor
		/** and what should I do for destructor of Circle */
		~Circle();

		Point center() const override;
		void move(Point to) override;

		void draw() const override;
		void rotate(int d) override;
	private:
		Point _x;  // center
		int _r;  // radius
};

#endif