// cpp file for "getstreamwidth.hpp"

#include "../inc/getstreamwidth.hpp"

std::streamsize get_stream_width(double number) {
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

std::streamsize get_stream_width(double number, const std::streamsize& num_decimals) {
	std::streamsize num_digits = num_decimals;
	if (number < 0) {
		num_digits = 3 + num_decimals;
		number = -number;
	}
	else {
		num_digits = 2 + num_decimals;
	}
	while (number >= 1) {
		number /= 10;
		++num_digits;
		--number;
	}
	return num_digits;
}