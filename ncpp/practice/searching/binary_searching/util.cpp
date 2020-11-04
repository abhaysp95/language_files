#include "util.hpp"
#include <iostream>


void print(int *arr, int &size) {
	for (int i = 0; i < size; ++i) {
		std::cout << *(arr + i) << std::endl;
	}
}

void sort(int *arr, int &size) {
	for (int i = 1; i < size ; ++i) {
		int key = *(arr + i);
		int j = i - 1;
		while (j >= 0 && *(arr + j) > key) {
			*(arr + j + 1) = *(arr + j);
			j -= 1;
		}
		*(arr + j + 1) = key;
	}
}

int binarySearch(int *arr, int min, int max, int key) {
	if (max >= 1) {
		int mid = min + (max - min) / 2;
		if (*(arr + mid) == key) {
			return mid;
		}
		if (*(arr + mid) > key) {
			return binarySearch(arr, min, mid - 1, key);
		}
		else {
			return binarySearch(arr, mid + 1, max, key);
		}
	}
	return -1;
}
