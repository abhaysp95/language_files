#ifndef _TOUGHPACK_HPP
#define _TOUGHPACK_HPP

#include "box.hpp"

class ToughPack: public Box {
	public:
		ToughPack(double l, double b, double h)
			: Box {l, b, h} {}

		inline double volume(int i = 500) const override {
			std::cout << "ToughPack parameter = " << i << std::endl;
			return 0.85 * (length * width * height);
		}
};

#endif
