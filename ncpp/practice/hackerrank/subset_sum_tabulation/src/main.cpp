// main file

#include <iostream>
#include <vector>

using namespace std;

bool subset_sum(size_t count, const vector<int>& arr, int target) {
	vector<vector<bool>> lookup;
	lookup.resize(count + 1, vector<bool>(target + 1, false));  // a 2d-array
	for (size_t i = 0; i <= count; ++i) {
		for (size_t j = 0; j <= target; ++j) {
			if (i == 0)
				break;
			if (j == 0)
				lookup[i][j] = true;
			else if (arr[i - 1] > j)
				lookup[i][j] = lookup[i - 1][j];
			else
				lookup[i][j] = lookup[i - 1][j - arr[i - 1]] || lookup[i - 1][j];
		}
	}
	return lookup[count][target];
}

int main(int argc, char **argv) {
	size_t count{};
	cin >> count;
	vector<int> arr(count);
	for (size_t i = 0; i < count; ++i)
		cin >> arr[i];
	int target{};
	cin >> target;
	cout << ((subset_sum(count, arr, target) ? "True" : "False")) << endl;
	return 0;
}