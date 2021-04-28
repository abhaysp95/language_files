// main file

#include <iostream>
#include <cstring>

using namespace std;

int count_ss(const int* arr, int size, int sum) {
	if (!sum)
		return 1;
	if (!size)
		return 0;
	if (arr[size - 1] > sum)
		count_ss(arr, size - 1, sum);
	return count_ss(arr, size - 1, sum) + count_ss(arr, size - 1, sum - arr[size - 1]);
}

int t[100][1000];
int count_ss_mem(const int* arr, int size, int sum) {
	if (!sum)
		return 1;
	if (!size)
		return 0;
	if (t[size][sum] != -1)
		return t[size][sum];
	if (arr[size - 1] > sum)
		return count_ss_mem(arr, size - 1, sum);
	t[size][sum] = count_ss(arr, size - 1, sum) + count_ss(arr, size - 1, sum - arr[size - 1]);
	return t[size][sum];
}

int count_ss_tab(const int* arr, int size, int sum) {
	for (size_t i = 0; i <= sum; ++i)
		t[0][i] = 0;  // no element provided, so false
	for (size_t i = 0; i <= size; ++i)
		t[i][0] = 1;  // target sum is zero, so true

	for (size_t i = 1; i <= size; ++i) {
		for (size_t j = 1; j <= sum; ++j) {
			if (arr[i - 1] > j)
				t[i][j] = t[i - 1][j];
			else
				t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
		}
	}
	return t[size][sum];
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	size_t size{};
	cin >> size;
	int arr[size];
	for (size_t i = 0; i < size; i++) {
		cin >> arr[i];
	}
	int target{};
	cin >> target;
	memset(t, -1, sizeof(t));
	cout << "Count: " << count_ss_tab(arr, size, target) << endl;
	return 0;
}