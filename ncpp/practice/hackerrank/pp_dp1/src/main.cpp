// main file

#include <iostream>
#include <vector>


using namespace std;

int get_count(int num) {
	if (num == 1) {
		return 0;
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
	if (num1 < num2) {
		if (num1 < num3) {
			return num1;
		}
		else {
			return num3;
		}
	}
	else if (num3 < num2) {
		return num3;
	}
	return num2;
}

int main() {
	int num{};
	cin >> num;
	int min_count = get_count(num);
	cout << min_count << '\n';
	return 0;
}