// main file

#include <iostream>
#include <vector>
#include <limits>
#include <ios>

int hourglass(std::vector<std::vector<int>> arr);
int get_sum(const std::vector<std::vector<int>>& arr, size_t x, size_t y);

int main(int argc, char **argv) {
	std::vector<std::vector<int>> arr(6);
	for (size_t i = 0; i < 6; ++i) {
		arr[i].resize(6);
		for (size_t j = 0; j < 6; ++j) {
			std::cin >> arr[i][j];
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	int result = hourglass(arr);
	std::cout << result << std::endl;
	return 0;
}

int hourglass(std::vector<std::vector<int>> arr) {
	int max = std::numeric_limits<int>::min();
	int sum{};
	// since question already says 6x6 array, we can use it
	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 4; ++j) {
			sum = get_sum(arr, i, j);
			if (max < sum) {
				max = sum;
			}
		}
	}
	return max;
}

int get_sum(const std::vector<std::vector<int>>& arr, size_t x, size_t y) {
	int sum{};
	for (size_t i = x; i < x + 3; ++i) {
		for (size_t j = y; j < y + 3; ++j) {
			if (i != (x + 1)) {
				sum += arr[i][j];
			}
			else if (j == (y + 1)) {
				sum += arr[i][j];
			}
		}
	}
	return sum;
}