// main file

#include <iostream>
#include <iomanip>

size_t get_square(const int& number) {
	return number * number;
}

size_t get_max_padding(const int& num) {
	size_t number = get_square(num);
	int count{0};
	while (number > 0) {
		number /= 10;
		count++;
	}
	return count;
}

int main(int argc, char **argv) {
	size_t max_num = 1000;
	size_t max_padding = get_max_padding(max_num) + 10;
	std::cout << "Printing square of 1 to 100" << std::endl;
	std::cout << "num" << std::setw(max_padding) << "square" << std::endl;
	for (size_t i = 1; i < max_num; ++i) {
		std::cout << i;
		std::cout << std::setw(max_padding) << get_square(i) << std::endl;
	}
	return 0;
}

/** some other important functions like std::setw() from <iomanip> are
 * std::setbase(), std::setfil() */