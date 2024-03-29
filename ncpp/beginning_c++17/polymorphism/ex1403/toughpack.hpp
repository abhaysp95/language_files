#ifndef _TOUGHPACK_HPP
#define _TOUGHPACK_HPP

#include "box.hpp"

class ToughPack: public Box {
	public:
		ToughPack(double l, double b, double h)
			: Box {l, b, h} {}

	protected:
		inline double volume() const override {
			return 0.85 * (length * width * height);
		}
};

#endif
