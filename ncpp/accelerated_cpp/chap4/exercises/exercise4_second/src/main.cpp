// main file

#include "../inc/getstreamwidth.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>

/** TODO: make it correct between -1 and 1 */

int main(int argc, char **argv) {
	double start{0};
	double end{0};
	const double increment{0.05};
	const std::streamsize d = 3;  // number of decimal places
	std::cout << "Enter start and end(both decimal, if you wish): " << std::endl;
	std::cout << "start: ";
	std::cin >> start;
	std::cout << "end: ";
	std::cin >> end;
	const std::streamsize col_width1 = std::max(get_stream_width(start, d), get_stream_width(end, d));
	const std::streamsize col_width2 = std::max(get_stream_width(start * start, d), get_stream_width(end * end, d));
	std::streamsize gap{0};
	if (start < 0 || end < 0) {
		gap = 3;
	}
	else {
		gap = 2;
	}
	const std::streamsize col1_precision = col_width1 - gap;
	const std::streamsize col2_precision = col_width2 - 2;
	const std::streamsize prec = std::cout.precision();
	while (start < end) {
		std::cout << std::setw(col_width1) << std::setprecision(col1_precision) << start
			<< std::setw(col_width2) << std::setprecision(col2_precision) << (start * start) << std::endl;
		start += increment;
	}
	std::setprecision(prec);
	return 0;
}