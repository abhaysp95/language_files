#include <iostream>

// TODO:
// find upper_bound and lower_bound with binary_search

/**
 * return the first number greater than num, if not found return the last index
 * (size)
 */
int
upper_bound(int *arr, int size, int num)
{
	int x = arr[0];

	for (int i = 0; i < size; i++) {
		if (x > num) {
			return i;
		}
		x = arr[i];
	}
	return size;
}

int
upper_bound_bs(int *arr, int size, int num)
{
	int low = 0;
	int high = size;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] <= num)
			low = mid + 1;
		else
			high = mid - 1;  // if you do "high = mid;" then cond. for while will (low < high)
	}

	return low;
}

int
lower_bound_bs(int *arr, int size, int num)
{
	int low = 0;
	int high = size;

	while (low < high) {
		int mid = (low + high) / 2;
		if (arr[mid] >= num)
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}

/**
 * return the first element in the range which has a value not less than val
 * (next smallest number, just greater than or equal to number)
 */
int
lower_bound(int *arr, int size, int num)
{
	int x = arr[0];
	for (int i = 0; i < size; i++) {
		if (x >= num) {
			return i;
		}
	}
	return size;
}

int
main(int argc, char **argv)
{
	int arr1[6] = {1, 3, 6, 6, 8, 9};
	// printf("%d\n", upper_bound(arr1, 6, 30));
	printf("%d\n", upper_bound_bs(arr1, 6, 6));
	printf("%d\n", lower_bound_bs(arr1, 6, 6));
	return 0;
}
