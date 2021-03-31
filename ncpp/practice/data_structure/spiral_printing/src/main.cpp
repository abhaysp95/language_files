// main file

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	int** arr2d = new int*[6];
	*(arr2d + 0) = new int[6]{1, 5, 7, 9, 10, 11};
	*(arr2d + 1) = new int[6]{6, 10, 12, 13, 20, 21};
	*(arr2d + 2) = new int[6]{9, 25, 29, 30, 32, 41};
	*(arr2d + 3) = new int[6]{15, 55, 59, 63, 68, 70};
	*(arr2d + 4) = new int[6]{40, 70, 79, 81, 95, 105};

	// spiral printing
	size_t row_start{};
	size_t col_start{};
	size_t row_end{4};
	size_t col_end{5};

	while (row_start <= row_end && col_start <= col_end) {
		for (size_t col = col_start; col <= col_end; ++col) {
			cout << *(*(arr2d + row_start) + col) << " ";
		}
		row_start++;

		for (size_t row = row_start; row <= row_end; ++row) {
			cout << *(*(arr2d + row) + col_end) << " ";
		}
		col_end--;

		// use 'int' instead of size_t when you are doing decrement, because 0-1 is unexpected result for size_t
		for (int col = col_end; col >= (int)col_start; --col) {
			cout << *(*(arr2d + row_end) + col) << " ";
		}
		row_end--;

		for (int row = row_end; row >= (int)row_start; --row) {
			// last element is printing because of >=
			cout << *(*(arr2d + row) + col_start) << " ";
		}
		col_start++;
	}

	for (size_t i = 0; i < 5; ++i) {
		delete[] *(arr2d + i);
	}
	delete[] arr2d;
	return 0;
}