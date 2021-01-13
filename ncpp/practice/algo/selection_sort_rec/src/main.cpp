// main file

#include <iostream>
#include <array>

#define MAX 10

void sort(std::array<int, MAX>& arr, size_t index);
size_t get_min_index(std::array<int, MAX>& arr, size_t index, size_t min_index);

int main(int argc, char **argv) {
	std::array<int, MAX> myarr = {9, 3, 7, 5, 6, 4, 8, 1, 2, 0};
	sort(myarr, 0);
	for (const int& num: myarr) {
		std::cout << num << std::endl;
	}
	return 0;
}

void sort(std::array<int, MAX>& arr, size_t index) {
	if (index != MAX - 1) {
		int min_index = index + 1;
		size_t get_next_min_index = get_min_index(arr, index + 1, min_index);
		if (arr[index] > arr[get_next_min_index]) {
			int temp = arr[index];
			arr[index] = arr[get_next_min_index];
			arr[get_next_min_index] = temp;
		}
		sort(arr, index + 1);
	}
}

size_t get_min_index(std::array<int, MAX>& arr, size_t index, size_t min_index) {
	if (index == MAX) {
		return min_index;
	}
	if (arr[index] < arr[min_index]) {
		min_index = index;
	}
	return get_min_index(arr, index + 1, min_index);
}