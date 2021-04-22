// main file

#include <iostream>
#include <vector>

using namespace std;

int get_count(int num) {
	static vector<int> arr(num + 1, -1);
	if (num == 0 || num == 1)
		return 1;
	if (arr.at(num) != -1)
		return arr.at(num);
	if (num == 1)
		arr.at(num) = get_count(num - 1);
	else if (num == 2)
		arr.at(num) = get_count(num - 1) + get_count(num - 2);
	else
		arr.at(num) = get_count(num - 1) + get_count(num -2) + get_count(num - 3);
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