// process of recursive merge sort

#include <stdio.h>
#include "mergesort.h"
#define SIZE 10

void printArr(int *);
/*void mergesort(int *arr, int low, int high);*/
/*void merge(int *, int, int, int);*/

int main(int argc, char **argv) {
	int arr[10];
	puts("Enter the 10 elements in array: ");
	for (int i = 0; i < SIZE; ++i) {
		scanf("%d", arr + i);
	}
	puts("Before sorting,");
	printArr(arr);
	mergesort(arr, 0, SIZE - 1);
	puts("After sorting,");
	printArr(arr);
	return 0;
}

void printArr(int *arr) {
	puts("Elements in array are: ");
	for (int i = 0; i < SIZE; ++i) {
		printf("%d\n", *(arr + i));
	}
}


/*void mergesort(int *arr, int low, int high) {
	// high is size of array - 1
	if (low < high) {
		int mid = (low + high) / 2;
		mergesort(arr, low, mid);
		mergesort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}*/


/*void merge(int *arr, int low, int mid, int high) {
	[>printf("from print, got low: %d, mid: %d, high: %d\n", low, mid, high);<]
	int start = low;
	[>while (start <= high) {<]
		[>printf("%d\n", *(arr + start++));<]
	[>}<]
	int extra[high - low + 1];
	int walk = 0;
	int middle = mid;
	[>start = low;<]
	while ((low <= middle) && (mid + 1 <= high)) {
		if (*(arr + low) < *(arr + mid + 1)) {
			*(extra + walk++) = *(arr + low++);
		}
		else {
			*(extra + walk++) = *(arr + mid++ + 1);
		}
	}
	while (low <= middle) {
		*(extra + walk++) = *(arr + low++);
	}
	while (mid + 1 <= high) {
		*(extra + walk++) = *(arr + mid++ + 1);
	}
	[>printf("Walk is %d\n", walk);<]
	[>puts("Content of extra: ");<]
	[>for (int i = 0; i < walk; ++i) {<]
		[>printf("%d\n", *(extra + i));<]
	[>}<]
	// copy the element of extra back to arr
	for (int i = 0; i < walk; ++i) {
		*(arr + start++) = *(extra + i);
	}
}*/
