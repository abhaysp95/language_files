// process of iterative merge sorting

#include <stdio.h>
#define SIZE 10


// #define MIN(x, y) (x < y ? x++ : y++)
/* this will not work since you don't have to increment number after finding smallest but to increment the counter to which number is smallest */

void mergesort(int *);
void merge(int *, int, int, int);

void mergesort(int *arr) {
	int pass = 0, low = 0, mid = 0, high = 0, i = 0;

	// every pass, can find the number of pass by log(SIZE) of base 2
	for (pass = 2; pass <= SIZE; pass *= 2) {
		// list to get sort according to number of pass
		for (i = 0; i + pass - 1 < SIZE; i += pass) {
			low = i;
			high = i + pass - 1;
			mid = (low + high) / 2;  // floor value
			merge(arr, low, mid, high);
		}
	}

	// if SIZE is odd
	if (pass / 2 < SIZE) {
		merge(arr, 0, (pass / 2 - 1), SIZE - 1);
	}
}

// try to do this without using another array(tried, maybe theirs a way but imo interchanging is not that)
void merge(int *arr, int low, int mid, int high) {
	int i = low, j = mid + 1, k = low;
	int brr[SIZE];

	// get the minimum first in the second array
	while (i <= mid && j <= high) {
		if (*(arr + i) < *(arr + j)) {
			*(brr + k++) = *(arr + i++);
		}
		else {
			*(brr + k++) = *(arr + j++);
		}
	}
	// put the remaining elements in the second array
	for (;i <= mid; ++i, ++k) {
		*(brr + k) = *(arr + i);
	}
	for (;j <= high; ++j, ++k) {
		*(brr + k) = *(arr + j);
	}

	// put all the elements back to first array
	for (i = low; i <= high; ++i) {
		*(arr + i) = *(brr + i);
	}
}


void print_array(int *arr) {
	printf("Array is: \n");
	for (int i = 0; i < SIZE; ++i) {
		printf ("%d\n", *(arr + i));
	}
	printf("\n");
}

int main(int argc, char **argv) {
	int array[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};

	mergesort(array);

	print_array(array);
	return 0;
}
