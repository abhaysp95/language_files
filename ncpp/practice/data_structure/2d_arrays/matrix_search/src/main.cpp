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
	cin >> size;
	cout << "Size is: " << size << '\n';
	int** arr2d = new int*[size];

	for (size_t i = 0; i < size; ++i) {
		*(arr2d + i) = new int[size];
		for (size_t j = 0; j < size; ++j) {
			cin >> *(*(arr2d + i) + j);
		}
	}

	size_t target{};
	cin >> target;
	cout << "Target: " << target << '\n';

	cout << "Entered matrix: \n";
	print_matrix(arr2d, size);

	size_t row{};
	int col{(int)size - 1};
	bool target_found{false};

	while (row < size && col >= 0) {
		if (*(*(arr2d + row) + col) == target) {
			cout << "target found: (" << (row + 1) << ", " << (col + 1) << ")\n";
			target_found = true;
			break;
		}
		else {
			if (*(*(arr2d + row) + col) > target) {
				col--;
			}
			else {
				row++;
			}
		}
	}

	if (!target_found) {
		cout << "Target not found\n";
	}

	return 0;
}