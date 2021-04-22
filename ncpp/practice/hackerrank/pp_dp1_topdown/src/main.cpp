// main file

#include <iostream>

using namespace std;

int get_min(int n1, int n2, int n3) {
	if (n1 < n2) {
		if (n1 < n3)
			return n1;
		else
			return n3;
	}
	else if (n3 < n2)
		return n3;
	return n2;
}

void get_count(int num) {
	int* arr = new int[num + 1];
	int count = 0;
	while (count <= num) {
		if ((count == 0) || (count == 1)) {
			*(arr + count++) = 0;
			continue;
		}
		int num1 = INT32_MAX;
		int num2 = INT32_MAX;
		int num3 = INT32_MAX;
		num1 = 1 + *(arr + count - 1);
		if ((count - (count / 2) * 2) == 0) {
			num2 = 1 + *(arr + (count / 2));
		}
		if ((count - (count / 3) * 3) == 0) {
			num3 = 1 + *(arr + (count / 3));
		}
		*(arr + count) = get_min(num1, num2, num3);
		count++;
	}
	cout << *(arr + num) << endl;
	delete[] arr;
}

int main(int argc, char **argv) {
	int num{};
	cin >> num;
	get_count(num);
	return 0;
}