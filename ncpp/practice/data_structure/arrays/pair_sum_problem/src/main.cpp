// main file

#include <iostream>
#include <cassert>

bool brute_force_way(const int* arr, const size_t& arr_size, const int& key_sum);
bool better_way(const int* arr, const size_t& arr_size, const int& key_sum);
void sort(int* arr, const size_t& arr_size);  // sort in non-decreasing order
void insertion_sort(int* arr, const size_t& arr_size);

int main(int argc, char **argv) {
	int key_sum{};
	std::cout << "Enter key sum: ";
	std::cin >> key_sum;
	size_t arr_size{};
	std::cout << "Enter array size: ";
	std::cin >> arr_size;
	assert(0 < arr_size);
	int* arr = new int[arr_size];
	std::cout << "Enter array elements: ";
	for (size_t idx = 0; idx < arr_size; ++idx) {
		std::cin >> *(arr + idx);
	}

	/*if (brute_force_way(arr, arr_size, key_sum)) {
		std::cout << "Pair found";
	}
	else {
		std::cout << "Pair not found";
	}*/

	sort(arr, arr_size);
	if (better_way(arr, arr_size, key_sum)) {
		std::cout << "Pair found";
	}
	else {
		std::cout << "Pair not found";
	}
	std::cout << std::endl;
	return 0;
}

void sort(int* arr, const size_t& arr_size) {
	if (arr_size < 20) {
		// insertion sort is better for array with small size
		insertion_sort(arr, arr_size);
	}
	else {
		// do quick sort
	}
}

void insertion_sort(int* arr, const size_t& arr_size) {
	for (size_t idx = 1; idx < arr_size; ++idx) {
		int key = *(arr + idx);
		size_t sidx = idx - 1;
		while (sidx > 0 && *(arr + sidx) > key) {
			*(arr + sidx + 1) = *(arr + sidx);
			sidx--;
		}
		*(arr + sidx) = key;
	}
}

size_t get_pivot(const int* arr, const size_t& arr_size);
int* do_partition(int* arr, const size_t& arr_size);

// time complexity: O(n^2) worst case
bool brute_force_way(const int* arr, const size_t& arr_size, const int& key_sum) {
	for (size_t idx = 0; idx < arr_size - 1; ++idx) {
		for (size_t sidx = idx + 1; sidx < arr_size; ++sidx) {
			if (*(arr + idx) + *(arr + sidx) == key_sum) {
				return true;
			}
		}
	}
	return false;
}

// time complexity: O(n)
bool better_way(const int* arr, const size_t& arr_size, const int& key_sum) {
	// need sorted array(sort it first before calling this function)
	int head = 0;  // first element
	int tail = arr_size - 1;  // last element
	while (head < tail) {
		if (*(arr + head) + *(arr + tail) == key_sum) {
			return true;
		}
		if (*(arr + head) + *(arr + tail) > key_sum) {
			tail--;
		}
		else {
			head++;
		}
	}
	return false;
}