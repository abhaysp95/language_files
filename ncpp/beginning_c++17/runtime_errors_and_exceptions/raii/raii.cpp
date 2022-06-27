#include "mytroubles.hpp"
#include "doublearray.hpp"

#include <cmath>
#include <iostream>
#include <typeinfo>

double do_compute_values(double);
double* compute_values(size_t);

int main(void) {
	try {
		double* values = compute_values(10000);  // use value less than 100 for exp.
		// std::cout << values[2] << std::endl;  // just for check with DoubleArray::get()
		delete[] values;
	} catch(const Trouble&) {
		std::cout << "Don't worry, I've caught it" << std::endl;
	}

	return 0;
}

double* compute_values(size_t how_many) {
	DoubleArray values{ how_many };
	for (size_t i{}; i < how_many; ++i) {
		values[i] = do_compute_values(i);
	}

	return values.release();  // dont use DoubleArray::get() for return as there will be chances for "double free"
}

double do_compute_values(double value) {
	if (value < 100) {
		return std::sqrt(value);
	} else {
		throw Trouble{ "The trouble with trouble is, it starts out as fun!!!" };
	}
}
