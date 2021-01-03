// cpp file for "getstreamwidth.hpp"

#include "../inc/getstreamwidth.hpp"

std::streamsize get_stream_width(int number) {
	std::streamsize num_width{0};
	if (number < 0) {
		num_width = 2;
		number = -number;
	}
	else {
		num_width = 1;
	}
	while (number != 0) {
		number /= 10;
		++num_width;
	}
	return num_width;
}