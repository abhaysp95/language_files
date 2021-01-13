// main file

#include <iostream>
#include <iomanip>
#include <ios>

int main(int argc, char **argv) {
	size_t row_len{0};
	std::cin >> row_len;
	for (int i = 0; i < row_len; ++i) {
		std::cout << std::string(row_len - i - 1, ' ') << std::string((2 * i) + 1, '*')  << std::endl;
	}
	return 0;
}


/*std::cout << std::right << std::setfill(' ')
	<< std::setw(12) << std::string(row_len + i, '1') << std::endl;*/