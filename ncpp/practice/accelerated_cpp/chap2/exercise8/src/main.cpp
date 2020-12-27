// main file

#include <iostream>

int product(const int& begin, const int& end) {
	if (begin == end) {
		return begin;
	}
	return end * product(begin, end - 1);
}

int main(int argc, char **argv) {
	int begin = 1;
	int end = 10;
	// since range is supposed to be inclusive
	std::cout << product(begin, end - 1);
	return 0;
}