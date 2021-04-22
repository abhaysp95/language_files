// main file

#include <iostream>
#include <vector>

using namespace std;

int get_min(int n1, int n2, int n3) {
	if (n1 < n2) {
		if (n1 < n3) {
			return n1;
		}
		else {
			return n3;
		}
	}
	else if (n3 < n2) {
		return n3;
	}
	return n2;
}

int get_count(int num) {
	static vector<int> arr(num + 1, -1);
	if (num == 1) {
		return 0;
	}
	if (arr.at(num) != -1) {
		return arr.at(num);
	}
	int num1 = INT32_MAX;
	int num2 = INT32_MAX;
	int num3 = INT32_MAX;
	num1 = 1 + get_count(num - 1);
	if ((num - (num / 2) * 2) == 0) {
		num2 = 1 + get_count(num / 2);
	}
	if ((num - (num / 3) * 3) == 0) {
		num3 = 1 + get_count(num / 3);
	}
	arr[num] = get_min(num1, num2, num3);
	return arr.at(num);
}

int main(int argc, char **argv) {
	int num{};
	cin >> num;
	int out = get_count(num);
	cout << out << endl;
	return 0;
}