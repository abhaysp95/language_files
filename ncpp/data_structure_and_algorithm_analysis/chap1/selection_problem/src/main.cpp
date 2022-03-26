// main file

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
	vector<int> nums{};
	size_t k_pos{};
	cin >> k_pos;
	for (size_t i = 0; i < k_pos; ++i) {
		int elem{};
		cin >> elem;
		nums.push_back(elem);
	}
	// sort the k entered elements in decreasing order
	sort(nums.begin(), nums.end(), [](const int& a, const int& b) {
			return a > b;
			});
	int elem{};
	while (cin >> elem) {
		if (elem > nums.at(k_pos - 1)) {
			for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) {
				if (*iter < elem) {
					*iter = elem;
					break;
				}
			}
		}
	}
	cout << "kth largest element: " << nums.at(k_pos - 1) << endl;
	return 0;
}


// this is just another way of doing the problem, rather than taking whole
// array as input and then sorting in decreasing order and the giving kth
// element back

// this isn't a better algorithm persay, we'll see a better one later