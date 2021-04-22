// main file

#include <iostream>
#include <vector>

using namespace std;

int get_count(int num) {
	vector<int> arr(num + 1, -1);
	for (size_t i = 0; i <= static_cast<size_t>(num); ++i) {
		if (i == 0 || i == 1) {
			arr.at(i) = 1;
			continue;
		}
		if (i == 2)
			arr.at(i) = arr.at(i - 1) + arr.at(i - 2);
		else if (i >= 3)
			arr.at(i) = arr.at(i - 1) + arr.at(i - 2) + arr.at(i - 3);
	}
	return arr.at(num);
}

int main(int argc, char **argv) {
	int num{};
	cin >> num;
	int res{};
	if (num != 0) {
		res = get_count(num);
	}
	cout << res << endl;
	return 0;
}