// main file

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

size_t
get_max_profit(const vector<size_t>& vlarr, const vector<size_t>& wtarr, size_t bc,
		size_t count, vector<vector<int>>& matrix) {
	// I don't wan't to change the matrix size with every recursive calls, it should be just one time procedure

	if (bc == 0 || count == 0) {
		return 0;
	}
	if (matrix[count][bc] != -1)
		return matrix[count][bc];
	if (wtarr[count - 1] > bc)
		return get_max_profit(vlarr, wtarr, bc, count - 1, matrix);
	matrix[count][bc] = max(
			vlarr[count - 1] + get_max_profit(vlarr, wtarr, bc - wtarr[count - 1], count - 1, matrix),
			get_max_profit(vlarr, wtarr, bc, count - 1, matrix));
	return matrix[count][bc];
}

int main(int argc, char **argv) {
	size_t bc{};
	size_t count{};
	cin >> bc >> count;
	vector<size_t> wtarr(count);
	vector<size_t> vlarr(count);
	for (size_t i = 0; i < count; ++i) {
		cin >> wtarr[i];
	}
	for (size_t i = 0; i < count; ++i) {
		cin >> vlarr[i];
	}
	static vector<vector<int>> matrix;
	matrix.resize(count + 1, vector<int>(bc + 1, -1));
	size_t res = get_max_profit(vlarr, wtarr, bc, count, matrix);
	cout << res << endl;
	return 0;
}