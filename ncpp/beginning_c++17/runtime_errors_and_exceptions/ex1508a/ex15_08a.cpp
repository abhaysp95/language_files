#include "mytroubles.hpp"

#include <cmath>
#include <iostream>
#include <typeinfo>

double do_compute_values(double);
double* compute_values(size_t);

int main(void) {
	try {
		double* values = compute_values(10000);
		delete[] values;
	} catch(const Trouble&) {
		std::cout << "Don't worry, I've caught it" << std::endl;
	}

	return 0;
}

double* compute_values(size_t how_many) {
	double* values = new double[how_many];
	try {
		for (size_t i{}; i < how_many; ++i) {
			values[i] = do_compute_values(i);
		}
		return values;  // can put this at end of the function too
	} catch (const Trouble&) {
		std::cout << "Sensing trouble... Freeing memory..." << std::endl;
		delete[] values;
		throw;
	}
}

double do_compute_values(double value) {
	if (value < 100) {
		return std::sqrt(value);
	} else {
		throw Trouble{ "The trouble with trouble is, it starts out as fun!!!" };
	}
}
