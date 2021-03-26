// main file

/** given an unsorted subarray of size N of non-negative integers, find a
  continuous subarray which adds to a given number S. */

/** Now, there can be two things, either you only have to give one set of this
  subarray which adds upto S or there can be more than one subarray which can
  add upto S, so I'm using the first one and will provide the index(range) of
  the subarray as answer */

#include <iostream>

int* get_subarray_index_range(const int* arr, const size_t& arr_size, const size_t& target_sum);

int main(int argc, char **argv) {
	size_t arr_size{};
	int target_sum{};
	std::cout << "Enter array size: ";
	std::cin >> arr_size;
	std::cout << "Enter target sum: ";
	std::cin >> target_sum;
	int* arr = new int[arr_size];
	std::cout << "Enter array elements: ";
	for (size_t idx = 0; idx < arr_size; ++idx) {
		std::cin >> *(arr + idx);
	}
	int* range = get_subarray_index_range(arr, arr_size, target_sum);
	std::cout << "Range: [" << *range << ", " << *(range + 1) << "]" << std::endl;
	delete[] arr;
	delete[] range;
	return 0;
}

int* get_subarray_index_range(const int* arr, const size_t& arr_size, const size_t& target_sum) {
	int* range = new int[2];
	bool sum_found = false;
	for (size_t idx = 0; idx < arr_size; ++idx) {
		int sum{};
		for (size_t sidx = idx; sidx < arr_size; ++sidx) {
			if (sum != target_sum) {
				if (sum > target_sum) {
					break;
				}
				sum += *(arr + sidx);
			}
			else {
				*range = idx + 1;  // answers index starts from 1
				*(range + 1) = sidx;  // and so we don't need to subtract 1 here
				sum_found = true;
				break;
			}
		}
		if (sum_found) {
			break;
		}
	}
	return range;
}