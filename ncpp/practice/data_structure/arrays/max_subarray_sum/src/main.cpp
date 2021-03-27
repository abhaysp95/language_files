// main file

#include <iostream>
#include <cassert>

int main(int argc, char **argv) {
	int arr_size{};
	std::cin >> arr_size;
	assert(0 < arr_size);
	int* arr = new int[arr_size];
	for (size_t idx = 0; idx < arr_size; ++idx) {
		std::cin >> *(arr + idx);
	}

	// kadane's algorithm
	// benefit, you don't need to have indexs for subarray and get their sum
	// and find max, it's just one simple 0(n) algo
	int current_sum{};
	int max_sum{INT8_MIN};
	for (size_t idx = 0; idx < arr_size; ++idx) {
		current_sum += *(arr + idx);
		if (current_sum < 0) {
			current_sum = 0;
		}
		max_sum = std::max(max_sum, current_sum);
	}
	std::cout << "Max sum: " << max_sum << std::endl;
	return 0;
}