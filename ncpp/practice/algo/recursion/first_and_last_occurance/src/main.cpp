// main file

#include <iostream>
#include <vector>

using namespace std;

void get_occurance(const int& target, const vector<int>& arr, int& foccur, int& loccur, int count) {
	if (count == -1)
		return;
	if (arr[count - 1] == target) {
		// since we are going in decreasing order of count, it'll first update loccur
		if (loccur == -1)
			loccur = count - 1;
		else
			foccur = count;
	}
	get_occurance(target, arr, foccur, loccur, count - 1);
}

int main(int argc, char **argv) {
	int target{};
	cin >> target;
	vector<int> arr{};
	int element{};
	while (cin >> element) {
		arr.push_back(element);
	}
	int foccur{-1}, loccur{-1};
	get_occurance(target, arr, foccur, loccur, arr.size());
	cout << foccur << ", " << loccur << endl;
	return 0;
}