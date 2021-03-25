// main file

#include <iostream>
#include <array>
#include <vector>
#define SIZE 10000

/** Struct for every testcase input */
struct TestInputs {
	size_t tnum{};
	size_t arr_len{};
	std::array<int, SIZE> arr{};
	size_t max_len_arithmetic_subarray{};
};

void calculate_lengths(std::vector<TestInputs>& inputs);
void print_results(const std::vector<TestInputs>& inputs);

int main(int argc, char **argv) {
	size_t test_cases{};
	std::cout << "Test cases: ";
	std::cin >> test_cases;
	std::vector<TestInputs> inputs{};  /** vector of all the testcases */
	TestInputs tempinput{};

	/** take the input */
	for (size_t i = 0; i < test_cases; ++i) {
		tempinput.tnum = i + 1;
		std::cout << (i + 1) << ": Enter array len: ";
		std::cin >> tempinput.arr_len;
		std::cout << (i + 1) << ": Enter array elements: ";
		for (size_t j = 0; j < tempinput.arr_len; ++j) {
			std::cin >> tempinput.arr[j];
		}
		inputs.push_back(tempinput);
		std::cout << '\n';
	}

	calculate_lengths(inputs);
	print_results(inputs);
	return 0;
}

void calculate_lengths(std::vector<TestInputs>& inputs) {
	for (TestInputs& tempinput: inputs) {
		int pcd = 0;  // previous common difference
		size_t current{1};
		size_t max_len{};
		for (size_t i = 1; i < tempinput.arr_len; ++i) {
			int diff = tempinput.arr[i] - tempinput.arr[i - 1];
			if (pcd != diff) {
				pcd = diff;
				max_len = std::max(max_len, current);
				current = 1;  // since, current will be incremented outside, so 1
			}
			current++;
		}
		max_len = std::max(max_len, current);  // in case last subarray is max len arithmetic subarray
		tempinput.max_len_arithmetic_subarray = max_len; }
}

void print_results(const std::vector<TestInputs>& inputs) {
	std::cout << "\n----------------------\n\n";
	for (const TestInputs& tempinput: inputs) {
		std::cout << tempinput.tnum << ": " << "[";
		for (size_t i = 0; i < tempinput.arr_len; ++i) {
			std::cout << tempinput.arr[i];
			if (i < tempinput.arr_len - 1) {
				std::cout << ", ";
			}
		}
		std::cout << "]\n";
		std::cout << "max len arithmetic subarray: " << tempinput.max_len_arithmetic_subarray << "\n";
		std::cout << std::endl;
	}
}

/** Question asked in Google Kick Start */