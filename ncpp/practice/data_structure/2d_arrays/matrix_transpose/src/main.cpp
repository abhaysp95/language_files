// main file

#include <iostream>

using namespace std;

// test how to pass 2d array with const parameter
void print_matrix(int** arr2d, const int& size) {
	// print array
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j) {
			cout << *(*(arr2d + i) + j);
			if (j < size - 1) {
				cout << " ";
			}
		}
		cout << '\n';
	}
}

int main(int argc, char **argv) {
	// square matrix
	size_t size{};
	cout << "Enter size: \n";
	cin >> size;
	int** arr2d = new int*[size];

	for (size_t i = 0; i < size; ++i) {
		*(arr2d + i) = new int[size];
		for (size_t j = 0; j < size; ++j) {
			cin >> *(*(arr2d + i) + j);
		}
	}

	cout << "Entered matrix: \n";
	print_matrix(arr2d, size);

	// just a simple logic to transpose
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = i; j < size; ++j) {
			if (i != j) {
				int temp = *(*(arr2d + i) + j);
				*(*(arr2d + i) + j) = *(*(arr2d + j) + i);
				*(*(arr2d + j) + i) = temp;
			}
		}
	}

	cout << "Transpose matrix: \n";
	print_matrix(arr2d, size);

	return 0;
}