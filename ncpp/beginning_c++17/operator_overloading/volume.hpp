#ifndef _VOLUME_HPP
#define _VOLUME_HPP

#include "cuboid.hpp"

class Volume {
	public:
		// function object (functor)
		inline double operator()(double l, double b, double h) {
			return l * b * h;
		}
		inline double operator()(const Cuboid& cuboid) {
			return cuboid.volume();
		}
};

// Unlike many other operators function object (and conversion operators,
// search it) can't be defined as normal function

#endif
