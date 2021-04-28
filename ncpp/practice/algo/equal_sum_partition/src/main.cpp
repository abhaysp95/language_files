// main file

#include <iostream>
#include <cstring>

using namespace std;

bool equal_sum_partition(int* arr, int size, long cur_sum, const long& sum) {
	if (!size) {
		if (cur_sum * 2 == sum)
			return true;
		return false;
	}
	if (arr[size - 1] > sum)
		return equal_sum_partition(arr, size - 1, cur_sum, sum);
	return equal_sum_partition(arr, size - 1, cur_sum, sum)
		|| equal_sum_partition(arr, size - 1, cur_sum + arr[size - 1], sum);
}

/*int t[100][1000];
int equal_sum_partition_mem(int* arr, int size, long cur_sum, const long sum) {
	if (!size) {
		if (cur_sum == sum)
			return 1;
		return 0;
	}
	if (t[size][cur_sum] != -1)
		return t[size][cur_sum];
	// if the required sum is less than the set element, then it would not make equal partition
	if (arr[size - 1] > sum)
		return equal_sum_partition_mem(arr, size - 1, cur_sum, sum);
	t[size][cur_sum] = equal_sum_partition_mem(arr, size - 1, cur_sum, sum)
		|| equal_sum_partition_mem(arr, size - 1, cur_sum + arr[size - 1], sum);
	return t[size][cur_sum];
}*/

bool t[100][1000];
bool equal_sum_partition_tab(int* arr, int size, long cur_sum) {
	long target_sum = cur_sum / 2;
	for (size_t i = 0; i <= size; ++i)
		t[i][0] = true;  // it means that target sum is zero
	for (size_t i = 0; i <= target_sum; ++i)
		t[0][i] = false;

	for (size_t i = 1; i <= size; i++) {
		for (size_t j = 1; j <= target_sum; j++) {
			if (arr[size - 1] > target_sum)
				t[i][j] = t[i - 1][j];
			else
				t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
		}
	}
	return t[size][target_sum];
}

// this is basically like subset sum, where the target sum will be the half of
// total sum of set, and then like subset sum problem, if it'll return true,
// then the result will be true

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int size{};
	cin >> size;
	int arr[size];
	long sum{};
	for (size_t i = 0; i < size; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	if ((sum - (sum / 2) * 2))
		cout << "False" << endl;
	else {
		//memset(t, -1, sizeof(t));
		//cout << ((equal_sum_partition_mem(arr, size, 0, sum / 2) ? "True" : "False")) << endl;
		cout << ((equal_sum_partition_tab(arr, size, sum) ? "True" : "False")) << endl;
	}
	return 0;
}