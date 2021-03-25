// main file

#include <iostream>
#include <array>
#define SIZE 6

void print_max(const std::array<int, SIZE>& arr);

int main(int argc, char **argv) {
	std::array<int, SIZE> arr = {1, 0, 5, 4, 6, 8};
	print_max(arr);
	return 0;
}

void print_max(const std::array<int, SIZE>& arr) {
	int max_idx = INT8_MIN;
	std::array<int, SIZE>::const_iterator arr_begin{arr.cbegin()};
	do {
		max_idx = std::max(max_idx, *arr_begin);  // use std::max, gives max of two elements
		std::cout << "Max: " << max_idx << '\n';
		arr_begin++;
	} while (arr_begin != arr.cend());
	std::cout << std::endl;
}

// time complexity: O(n), cause of single loop