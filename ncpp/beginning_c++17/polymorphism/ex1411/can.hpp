#ifndef _CAN_HPP
#define _CAN_HPP

#include "vessel.hpp"

#include <cmath>

class Can: public Vessel {
	protected:
		double diameter{ 1.0 };
		double height{ 1.0 };

	public:
		explicit Can(double d, double h)
			:diameter{d}, height{h} {}

		double volume() const override {
			return (M_PI * diameter * diameter * height) / 4.0;
		}
};

#endif
