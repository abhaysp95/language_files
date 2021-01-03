// main file

#include <iostream>
#include <cmath>
#include <iomanip>

double return_square(double num) {
	return num * num;
}

int main(int argc, char **argv) {
	double start_range{5};
	const double end_range{6};
	const double increment{0.05};
	std::streamsize prec = std::cout.precision();
	while (floor(start_range + increment) != end_range) {
		std::cout << start_range + increment << std::setprecision(3) << std::setw(14) << return_square(start_range + increment) << std::endl;
		start_range += increment;
	}
	std::setprecision(prec);
	return 0;
}

/** some other important functions like std::setw() from <iomanip> are
 * std::setbase(), std::setfil() */