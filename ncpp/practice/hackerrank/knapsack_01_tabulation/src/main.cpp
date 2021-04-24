// main file

#include <iostream>
#include <vector>

using namespace std;

long get_max_profit(const vector<size_t>& vlarr, const vector<size_t>& wtarr, size_t bc, size_t count) {
	vector<vector<long>> matrix;
	matrix.resize(count + 1, vector<long>(bc + 1, -1));
	for (size_t i = 0; i < count + 1; ++i) {
		for (size_t j = 0; j < bc + 1; ++j) {
			if (i == 0 || j == 0)
				matrix[i][j] = 0;
			else if (wtarr[i - 1] > j)
				matrix[i][j] = matrix[i - 1][j];
			else
				matrix[i][j] = max(static_cast<long>(vlarr[i - 1]) + matrix[i - 1][j - wtarr[i - 1]],
						matrix[i - 1][j]);
		}
	}
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
	long res = get_max_profit(vlarr, wtarr, bc, count);
	cout << res << endl;
	return 0;
}