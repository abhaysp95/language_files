// main file

#include <iostream>
#include <cassert>
#include <cmath>

bool brute_force_way(const int* arr, const size_t& arr_size, const int& key_sum);
bool better_way(const int* arr, const size_t& arr_size, const int& key_sum);
void sort(int* arr, const size_t& arr_size);  // sort in non-decreasing order
void insertion_sort(int* arr, const size_t& arr_size);
int median(const int* arr, const size_t& begin, const size_t& end);
void quicksort(int* arr, size_t begin, size_t end);
size_t partition(int* arr, size_t begin, size_t end);

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

	// sorting is not necessary for brute force way
	sort(arr, arr_size);

	printf("\nAfter sorting: \n[ ");
	for (size_t idx = 0; idx < arr_size; ++idx) {
		printf("%d", *(arr + idx));
		if (idx < arr_size - 1) {
			printf(", ");
		}
	}
	printf(" ]\n");

	// you can try brute_force_way() here too
	if (better_way(arr, arr_size, key_sum)) {
		std::cout << "Pair found";
	}
	else {
		std::cout << "Pair not found";
	}
	std::cout << std::endl;
	return 0;
}

int median(const int* arr, const size_t& begin, const size_t& end) {
	size_t mid = (begin + end) / 2;
	if (*(arr + begin) < *(arr + mid)) {
		if (*(arr + begin) >= *(arr + end)) {
			return *(arr + begin);
		}
		else if (*(arr + mid) < *(arr + end)) {
			return *(arr + mid);
		}
	}
	else {
		if (*(arr + begin) < *(arr + end)) {
			return *(arr + begin);
		}
		else if (*(arr + mid) >= *(arr + end)) {
			return *(arr + mid);
		}
	}
	return *(arr + end);
}

void sort(int* arr, const size_t& arr_size) {
	if (arr_size < 10) {  // this is the count which js uses to switch probably
		// insertion sort is better for array with small size
		insertion_sort(arr, arr_size);
	}
	else {
		// quicksort good with large set of elements
		quicksort(arr, 0, arr_size - 1);
	}
}

void insertion_sort(int* arr, const size_t& arr_size) {
	for (size_t idx = 1; idx < arr_size; ++idx) {
		size_t sidx = idx;
		while (sidx > 0 && *(arr + sidx) < *(arr + sidx - 1)) {
			int temp = *(arr + sidx);
			*(arr + sidx) = *(arr + sidx - 1);
			*(arr + sidx - 1) = temp;
			sidx--;
		}
	}
}

void quicksort(int* arr, size_t begin, size_t end) {
	size_t pivot_index{};

	if (begin != end) {
		pivot_index = partition(arr, begin, end);
	}

	// if begin reference is not incremented upto pivot element yet, keep comparing
	if (begin < pivot_index - 1) {
		quicksort(arr, begin, pivot_index - 1);
	}

	// if end reference is not upto pivot_index yet, keep comparing
	if (pivot_index < end) {
		quicksort(arr, pivot_index, end);
	}
}

size_t partition(int* arr, size_t begin, size_t end) {
	int pivot_element{};
	size_t left = begin;
	size_t right = end;

	if ((end - begin) > 2) {  // contains atleast 3 elements
		pivot_element = median(arr, begin, end);
	}
	else {
		pivot_element = *(arr + (int)floor((begin + end) / 2));
	}

	while (left <= right) {
		while (*(arr + left) < pivot_element) { left++; }
		while (*(arr + right) > pivot_element) { right--; }

		// swap left and right index elements if left & right haven't crossed each-other
		if (left <= right) {
			int temp = *(arr + left);
			*(arr + left) = *(arr + right);
			*(arr + right) = temp;

			left++;
			right--;
		}
	}
	return left;
}

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