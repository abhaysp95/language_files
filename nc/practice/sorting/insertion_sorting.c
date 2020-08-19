// insertion sorting

#include <stdio.h>
#define LENGTH 6

int *insertion_sort(int *);

int *insertion_sort(int *arr) {
	for (int i = 1; i < LENGTH; ++i) {
		int key = *(arr + i);
		int j = i - 1;
		while (j >= 0 && *(arr + j) > key) {
			*(arr + j + 1) = *(arr + j);
			j -= 1;
		}
		*(arr + j + 1) = key;
	}
	return arr;
}

int main(int argc, char **argv) {
	int array[LENGTH];
	printf("Enter 6 numbers for sorting: \n");
	for (int i = 0; i < LENGTH; ++i) {
		scanf("%d", array + i);
	}
	printf("You entered: \n");
	for (int i = 0; i < LENGTH; ++i) {
		printf("%d: %d\n", i, *(array + i));
	}
	int *sorted_array = insertion_sort(array);
	printf("Sorted array is: \n");
	for (int i = 0; i < LENGTH; ++i) {
		printf("%d: %d\n", i, *(sorted_array + i));
	}
	return 0;
}
