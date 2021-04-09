// main file

#include <iostream>

using namespace std;

void print_matrix(int** matrix, const size_t& row, const size_t& col) {
	for (size_t i = 0; i < row; ++i) {
		for (size_t j = 0; j < col; ++j) {
			cout << *(*(matrix + i) + j) << " ";
		}
		cout << endl;
	}
}

void do_transpose(int** matrix, const size_t& row_count, size_t col_count, const size_t& col) {
	static size_t count = 0;
	cout << "Called: " << count++ << '\n';
	if (col_count == col) {
		return;
	}
	if (row_count != col_count) {
		cout << "doing transpose\n";
		int temp = *(*(matrix + row_count) + col_count);
		*(*(matrix + row_count) + col_count) = *(*(matrix + col_count) + row_count);
		*(*(matrix + col_count) + row_count) = temp;
	}
	do_transpose(matrix, row_count, col_count + 1, col);
}

void matrix_transpose(int** matrix, const size_t& row, size_t row_count, const size_t& col) {
	if (row_count == row) {
		return;
	}
	// *(matrix + row_count) = new int[col];
	do_transpose(matrix, row_count, row_count, col);
	matrix_transpose(matrix, row, row_count + 1, col);
}

int main(int argc, char **argv) {
	size_t row{}, col{};
	cin >> row >> col;
	int** matrix = new int*[row];
	for (size_t i = 0; i < row; ++i) {
		*(matrix + i) = new int[col];
		for (size_t j = 0; j < col; ++j) {
			cin >> *(*(matrix + i) + j);
		}
	}
	matrix_transpose(matrix, row, 0, col);
	print_matrix(matrix, row, col);
	return 0;
}