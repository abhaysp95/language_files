// main file

#include <iostream>
#include <cstring>

using namespace std;

//int t[100][100];
/*int ss_mem(int size, int* arr, int target) {
	if (!size)
		return 0;
	if (!target)
		return 1;
	if (t[size][target] != -1)
		return t[size][target];
	if (arr[size - 1] > target)
		return ss_mem(size - 1, arr, target);
	t[size][target] = ss_mem(size - 1, arr, target - arr[size - 1])
		|| ss_mem(size - 1, arr, target);
	return t[size][target];
}*/

bool t[100][100];
bool ss_tab(int size, int* arr, int target) {
	for (size_t i = 0; i<= size; ++i)
		t[i][0] = true;
	for (size_t j = 0; j <= target; ++j)
		t[0][j] = false;

	for (size_t i = 1; i <= size; ++i) {
		for (size_t j = 1; j <= target; ++j) {
			if (arr[i - 1] > j)
				t[i][j] = t[i - 1][j];
			else
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
		}
	}
	return t[size][target];
}


int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int size{};
	cin >> size;
	int arr[size];
	for (int i = 0; i < size; ++i)
		cin >> arr[i];
	int target{};
	cin >> target;
	memset(t, -1, sizeof(t));
	cout << (ss_tab(size, arr, target) ? "True" : "False") << endl;;
	return 0;
}