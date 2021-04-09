// main file

#include <iostream>
#include <cmath>
#include <climits>

// #define get_max(x, y) ((x > y) ? x : y)  macro to find max

using namespace std;

int main(int argc, char **argv) {
	size_t tc{}, a{}, b{};
	cin >> tc >> a >> b;
	size_t sum{}, min_sum{INT_MAX};
	for (size_t i = tc; i > tc / 2; --i) {
		sum = (max(a, b) == b ? (a * pow(i, 2)) + (b * pow(tc - i, 2)) : (a * pow(tc - i, 2)) + (b * pow(i, 2)));
		min_sum = min(sum, min_sum);
	}
	cout << min_sum << endl;
	return 0;
}