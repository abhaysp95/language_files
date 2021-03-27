// main file

/** given an array of N integers including 0. Task is to find smallest +ve number
  missing from the array */

/** constraint
  1 <= N <= 10^6
  -10^6 <= Ai <= 10^6
*/

#include <iostream>
#include <cassert>

size_t get_smallest_missing_positive_int(const int* arr, const size_t& arr_size);

int main(int argc, char **argv) {
	size_t arr_size;
	std::cout << "Enter the array size: ";
	std::cin >> arr_size;



	// validate constraint for N here
	assert((arr_size >= 1) && (arr_size <= 10e5));

	int* arr = new int[arr_size];
	std::cout << "Enter array elements: ";
	for (size_t idx = 0; idx < arr_size; ++idx) {
		int element{};
		std::cin >> element;

		// validate constraint for Ai here
		assert((-10e5 <= element) && (element <= 10e5));

		*(arr + idx) = element;
	}


	size_t resultant_int = get_smallest_missing_positive_int(arr, arr_size);
	std::cout << "Missing smallest positive integer: " << resultant_int << std::endl;
	delete[] arr;
	return 0;
}

/** since question only requires +ve integer, I'm gonna neglect the negative integer */
size_t get_smallest_missing_positive_int(const int* arr, const size_t& arr_size) {
	int resultant_int = -1;  // -1 means can't find answer
	const size_t idx_arr_size = 10e6 + 1;
	bool* idx_arr = new bool[idx_arr_size];  // that's why size only 10e6+1
	// you can also find the max element from arr and make that size of idx_arr
	// it depends on priority for space or time
	for (size_t idx = 0; idx < idx_arr_size; ++idx) {
		*(idx_arr + idx) = false;
	}
	// need only +ve so start from 1
	for (size_t idx = 0; idx < arr_size; ++idx) {
		if (*(arr + idx) > 0) {
			if (*(idx_arr + arr[idx]) != true) {
				*(idx_arr + arr[idx]) = true;
			}
		}
	}
	// now find the minimum missing +ve integer
	for (size_t idx = 0; idx < idx_arr_size; ++idx) {
		if (*(idx_arr + idx) == false) {
			resultant_int = idx;
			break;
		}
	}
	delete[] idx_arr;
	return resultant_int;
}