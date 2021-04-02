// main file

#include <iostream>
#include <cstdlib>  // abs(int)

// abs in cmath are abs(float), abs(double), abs(long double)

using namespace std;

int main(int argc, char **argv) {
	size_t row{}, col{};  // position of 1 will be taken in these two
	size_t temp{};
	size_t moves{};
	for (size_t i = 0; i < 25; ++i) {
		cin >> temp;
		if (i % 5 == 0) {
			col = 1;
			row++;
		}
		else {
			col++;
		}
		if (temp == 1) {
			break;
		}
	}
	/* while (row != 3 || col != 3) {
		if (row != 3) {
			if (row > 3) {
				row--;
				moves++;
			}
			else if (row < 3) {
				row++;
				moves++;
			}
		}
		if (col != 3) {
			if (col > 3) {
				col--;
				moves++;
			}
			else if (col < 3) {
				col++;
				moves++;
			}
		}
	} */

	// this whole while block can be boiled down to
	moves = abs(int(row - 3)) + abs(int(col - 3));
	cout << moves << endl;
	return 0;
}