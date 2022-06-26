#ifndef _BOX_HPP
#define _BOX_HPP

#include <iostream>

class Box {
	protected:  // use private with accessor and mutator (on production or for better practice)
		double length{1.0};
		double width{1.0};
		double height{1.0};
	public:
		Box() = default;
		Box(double l, double w, double h)
			: length{l}, width{w}, height{h} {}

		/* ~Box() {
			std::cout << "Box destructor called" << std::endl;
		} */
		// non-virtual and virtual destructor can't be declared at same time
		virtual ~Box() = default;

		inline void showVolume() const {
			std::cout << "Volume of Box is " << volume() << std::endl;
		}

		inline virtual double volume() const {
			return length * width * height;
		}
};

#endif
