#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quicksort(int* arr, unsigned int begin, unsigned int end);
unsigned int median(int* arr, unsigned int begin, unsigned int end);
unsigned int partition(int* arr, unsigned int begin, unsigned int end);

int main(int argc, char** argv) {
	unsigned int arr_size;
	printf("Enter array size: ");
	scanf("%u", &arr_size);
	int* arr = (int*)malloc(sizeof(int) * arr_size);
	printf("Enter array elements: \n");
	for (unsigned int idx = 0; idx < arr_size; ++idx) {
		scanf("%d", (arr + idx));
	}
	quicksort(arr, 0, arr_size - 1);
	printf("\nAfter sorting: \n[ ");
	for (unsigned int idx = 0; idx < arr_size; ++idx) {
		printf("%d", *(arr + idx));
		if (idx < arr_size - 1) {
			printf(", ");
		}
	}
	printf(" ]\n");
	free(arr);
	return 0;
}

void quicksort(int* arr, unsigned int begin, unsigned int end) {
	unsigned int pivotIndex = 0;
	if (begin != end) {  // array is of more than one element
		pivotIndex = partition(arr, begin, end);
	}

	printf("\n** pivot is: %d\n", *(arr + pivotIndex));

	// if left reference is not incremented to reach pivot yet, keep comparing
	if (begin < pivotIndex - 1) {
		quicksort(arr, begin, pivotIndex - 1);
	}

	// if right reference is not to pivotIndex yet, keep comparing
	if (pivotIndex < end) {
		quicksort(arr, pivotIndex, end);
	}
}

unsigned int median(int* arr, unsigned int begin, unsigned int end) {
	unsigned int mid = (begin + end) / 2;
	if (*(arr + begin) < *(arr + mid)) {
		if (*(arr + begin) >= *(arr + end)) {
			return *(arr + begin);
		}
		else if (*(arr + mid) < *(arr + end)) {
			return *(arr + mid);
		}
	}
	else {
		if (*(arr + begin) < *(arr + end)) {
			return *(arr + begin);
		}
		else if (*(arr + mid) >= *(arr + end)) {
			return *(arr + mid);
		}
	}
	return *(arr + end);
}

unsigned int partition(int* arr, unsigned int begin, unsigned int end) {
	// get pivot element
	/*unsigned int pivot = *(arr + (int)floor((begin + end) / 2));*/

	// another good way to get pivot is to get median
	unsigned int pivot = median(arr, begin, end);

	unsigned int left = begin;
	unsigned int right = end;

	printf("** pivot: %u\n", pivot);
	printf("** left: %d\n", *(arr + left));
	printf("** right: %d\n", *(arr + right));

	while (left <= right) {
		while (*(arr + left) < pivot) {
			left++;
			printf("left pointing to: %d\n", *(arr + left));
		}
		while (*(arr + right) > pivot) {
			right--;
			printf("right pointing to: %d\n", *(arr + right));
		}

		// when left pointer reference becomes larger than pivot and right
		// becomes smaller than pivot, then swap left and right reference
		// elements
		if (left <= right) {
			int temp = *(arr + left);
			*(arr + left) = *(arr + right);
			*(arr + right) = temp;
			left++;
			right--;
		}
	}
	// left item is now new pivot element
	return left;
}
