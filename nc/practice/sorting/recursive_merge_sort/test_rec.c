#include <stdio.h>
#define SIZE 10

void printArr(int *);
void recursive(int *, int, int);
void print(int *, int, int);
void print2(int *, int, int);
void print3(int *, int, int, int);

int main(int argc, char **argv) {
	int arr[10];
	puts("Enter the 10 elements in array: ");
	for (int i = 0; i < SIZE; ++i) {
		scanf("%d", arr + i);
	}
	puts("Before sorting,");
	recursive(arr, 0, SIZE - 1);
	printArr(arr);
	return 0;
}

void printArr(int *arr) {
	puts("Elements in array are: ");
	for (int i = 0; i < SIZE; ++i) {
		printf("%d\n", *(arr + i));
	}
}

void recursive(int *arr, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		recursive(arr, low, mid);
		puts("Passed first recursion");
		recursive(arr, mid + 1, high);
		puts("Passed second recursion");
		print3(arr, low, mid, high);
	}
}

void print(int *arr, int a, int b) {
	printf("from print, got low: %d, mid: %d\n", a, b);
	while (a <= b) {
		printf("%d\n", *(arr + a++));
	}
}

void print2(int *arr, int a, int b) {
	printf("from print, got mid: %d, high: %d\n", a, b);
	while (a <= b) {
		printf("%d\n", *(arr + a++));
	}
}

void print3(int *arr, int a, int m, int b) {
	printf("from print, got low: %d, mid: %d, high: %d\n", a, m, b);
	while (a <= b) {
		printf("%d\n", *(arr + a++));
	}
}
