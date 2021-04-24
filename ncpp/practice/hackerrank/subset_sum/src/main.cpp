// main file

#include <iostream>
#include <vector>

using namespace std;

bool subset_sum(int count, const vector<int>& arr, int target) {
	if (target == 0)
		return true;
	if (count == 0)
		return false;
	if (arr[count - 1] > target)
		return subset_sum(count - 1, arr, target);
	return (subset_sum(count - 1, arr, target - arr[count - 1])
			|| subset_sum(count - 1, arr, target));
}

int main(int argc, char **argv) {
	int count{};
	cin >> count;
	vector<int> arr(count);  // this arr is treated as weight array from knapsack problem
	for (size_t i = 0; i < count; ++i) {
		cin >> arr[i];
	}
	int target{};
	cin >> target;
	cout << (subset_sum(count, arr, target) ? "True" : "False") << endl;
	return 0;
}