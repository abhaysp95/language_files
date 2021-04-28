// main file

#include <iostream>
#include <vector>

using namespace std;

/**
  In a grid(matrix), you begin travelling from top-left corner and you have to reach to the bottom-right corner. In how many ways, this can be done ?
  */

// recursive approach
void grid_travelling_ways(int x, int y, size_t& ways) {
	if (x == 0 || y == 0)
		return;
	if (x == 1 && y == 1) {
		ways += 1;
		return;
	}
	grid_travelling_ways(x - 1, y, ways);
	grid_travelling_ways(x, y - 1, ways);
}

// recursive approach
size_t grid_travelling_another(int x, int y) {
	if (!x || !y)
		return 0;
	if (x == 1 && y == 1)
		return 1;
	return grid_travelling_another(x - 1, y) + grid_travelling_another(x, y - 1);
}

// memoized approach
size_t grid_travelling_memoization(int x, int y, vector<vector<size_t>>& lookup) {
	if (!x || !y) {
		return 0;
	}
	if (x == 1 && y == 1) {
		return 1;
	}
	if (lookup[x][y] != -1) {
		return lookup[x][y];
	}
	lookup[x][y] = grid_travelling_memoization(x - 1, y, lookup) + grid_travelling_memoization(x, y - 1, lookup);
	return lookup[x][y];
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x{}, y{};
	cin >> x >> y;
	size_t ways{};
	//grid_travelling_ways(x, y, ways);
	//ways = grid_travelling_another(x, y);
	vector<vector<size_t>> vec;
	vec.resize(x + 1, vector<size_t>(y + 1, -1));
	ways = grid_travelling_memoization(x, y , vec);
	cout << ways << endl;
	return 0;
}