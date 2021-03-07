// header file

#ifndef _GUARD_SMILEY_HPP_
#define _GUARD_SMILEY_HPP_

#include "../inc/circle.hpp"
#include <vector>

/* do smiley will have vtable of its own ? */

class Smiley: public Circle {
	public:
		Smiley(Point p, int r);
		~Smiley();

		void move(Point to) override;

		void draw() const override;
		void rotate(int d) override;

		void add_eye(Shape* s);
		void set_mouth(Shape* s);
		virtual void wink(int i);  //wink eye number i
	private:
		std::vector<Shape*> _eyes;  // usually two eyes
		Shape* _mouth;
};

#endif