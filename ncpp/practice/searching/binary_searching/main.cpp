#include <iostream>
#include "util.hpp"

int main(int argc, char **argv) {
	int arr[] = {3, 5, 34, 9, 12, 10, 9, 39};  // we have array size 8
	int size = sizeof(arr) / sizeof(int);
	std::cout << "size is: " << size << std::endl;
	sort(arr, size);
	print(arr, size);
	int key = 10;
	int pos = binarySearch(arr, 1, size - 1, key);
	std::cout << "Position: " << pos + 1 << std::endl;
	print(arr1, size);
	return 0;
}
