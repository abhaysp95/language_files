// main file

#include <iostream>

size_t get_element_index_min(int* arr, const size_t& arr_size);

int main(int argc, char **argv) {
	std::cout << "Enter the size of array: ";
	size_t arr_size{};
	std::cin >> arr_size;
	int *arr = new int[arr_size];  // std::array can't have size from runtime
	std::cout << "Enter array elements: ";
	for (size_t idx = 0; idx < arr_size; ++idx) {
		std::cin >> *(arr + idx);
	}
	size_t min_index = get_element_index_min(arr, arr_size);
	std::cout << "Min index is: " << min_index << std::endl;
	delete[] arr;
	return 0;
}

/** we don't have to see if an element is repeated more than any other, but only
  which repeated element comes first, that's it */

size_t get_element_index_min(int* arr, const size_t& arr_size) {
	size_t min_index = INT8_MAX;
	int *idx_arr = new int[1e6+2];  // size 1000002(given as per question)
	for (size_t idx = 0; idx < 10; ++idx) {
		*(idx_arr + idx) = -1;
	}
	for (size_t idx = 0; idx < arr_size; ++idx) {
		// update the idx_arr index with the number from arr and put value of the
		// index from arr to idx_arr
		if (*(idx_arr + arr[idx]) != -1) {
			if (min_index > *(idx_arr + arr[idx])) {
				min_index = *(idx_arr + arr[idx]);
			}
		}
		else {
			*(idx_arr + arr[idx]) = idx + 1;
		}
	}
	if (min_index == INT8_MAX) {
		min_index = -1;  // if no repeating element found, give as -1
	}
	return min_index;
}