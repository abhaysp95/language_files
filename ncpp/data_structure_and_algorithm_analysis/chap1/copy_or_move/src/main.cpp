// main file

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> partial_sums(const vector<int>& arr) {
	vector<int> result( arr.size() );

	result[0] = arr[0];
	for (vector<int>::size_type i = 1; i < arr.size(); ++i) {
		result[i] = result[i - 1] + arr[i];
	}

	return result;
}

int main(int argc, char **argv) {
	vector<int> arr{};

	int elem;
	while (cin >> elem) {
		arr.push_back(elem);
	}

	vector<int> psums = partial_sums(arr);
	// result is not getting copied but moved
	/* address for 'result' and 'psums' are same */

	for (const int& x: psums) {
		printf("%d ", x);
	}
	cout << endl;
	return 0;
}