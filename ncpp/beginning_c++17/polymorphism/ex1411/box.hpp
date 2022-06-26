#ifndef _BOX_HPP
#define _BOX_HPP

#include "vessel.hpp"

#include <iostream>

class Box: public Vessel {
	protected:  // use private with accessor and mutator (on production or for better practice)
		double length{1.0};
		double width{1.0};
		double height{1.0};
	public:
		Box() = default;
		Box(double l, double w, double h)
			: length{l}, width{w}, height{h} {}

		virtual ~Box() = default;  // virtual destructor
		inline double volume() const override {
			return length * width * height;
		}
};

#endif
