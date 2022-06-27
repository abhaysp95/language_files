#include "mytroubles.hpp"

#include <cmath>
#include <iostream>
#include <memory>
#include <typeinfo>

double do_compute_values(double);
std::unique_ptr<double[]> compute_values(size_t);

int main(void) {
	try {
		std::unique_ptr<double[]> values = compute_values(99);  // try >= 100 for throwing exception
		// do something with values, it'll be freed with completion of try
		// block of with return of this function
		std::cout << "try successful" << std::endl;  // just for check
	} catch(const Trouble&) {
		std::cout << "Don't worry, I've caught it" << std::endl;
	}

	return 0;
}

std::unique_ptr<double[]> compute_values(size_t how_many) {
	std::unique_ptr<double[]> values = std::make_unique<double[]>(how_many);
	for (size_t i{}; i < how_many; ++i) {
		values[i] = do_compute_values(i);
	}

	return values;  // return the raii object itself (is much better, than releasing the encapsulated resource, mostly)
}

// not so good
/* double* compute_values(size_t how_many) {
	std::unique_ptr<double[]> values = std::make_unique<double[]>(how_many);
	for (size_t i{}; i < how_many; ++i) {
		values[i] = do_compute_values(i);
	}

	return values.release();
} */

double do_compute_values(double value) {
	if (value < 100) {
		return std::sqrt(value);
	} else {
		throw Trouble{ "The trouble with trouble is, it starts out as fun!!!" };
	}
}
