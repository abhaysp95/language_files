// main file

#include "../inc/getstreamwidth.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>

int main(int argc, char **argv) {
	int start{0};
	int end{0};
	std::cout << "Enter start and end: " << std::endl;
	std::cout << "start: ";
	std::cin >> start;
	std::cout << "end: ";
	std::cin >> end;
	std::streamsize col_width1 = std::max(get_stream_width(start), get_stream_width(end - 1));
	std::streamsize col_width2 = std::max(get_stream_width(start * start), get_stream_width((end - 1) * (end - 1)));
	while (start != end) {
		std::cout << std::setw(col_width1) << start << std::setw(col_width2) << (start * start) << std::endl;
		start++;
	}
	return 0;
}