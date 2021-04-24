// main file

#include <iostream>
#include <vector>

using namespace std;

bool subset_sum(int count, const vector<int>& arr, int target, vector<bool>& lookup) {
	if (target == 0)
		return true;
	if (count == 0)
		return false;
	if (lookup[count])
		return true;
	if (arr[count - 1] > target)
		lookup[count] = subset_sum(count - 1, arr, target, lookup);
	else
		lookup[count] = subset_sum(count - 1, arr, target - arr[count - 1], lookup)
			|| subset_sum(count - 1, arr, target, lookup);
	return lookup[count];
}

int main(int argc, char **argv) {
	size_t count{};
	cin >> count;
	vector<int> arr(count);
	for (size_t i = 0; i < count; ++i) {
		cin >> arr[i];
	}
	int target{};
	cin >> target;
	vector<bool> lookup(count + 1, false);
	cout << ((subset_sum(count, arr, target, lookup) ? "True" : "False")) << endl;;
	return 0;
}