#include <stdio.h>
#define LENGTH 5

void function_to_show_arr(int *);
void function_to_show_array(int *);

void function_to_show_arr(int *arr) {
	printf("printing inside function_to_show_array function:-\n");
	for (size_t i = 0; i < LENGTH; ++i) {
		printf("%d: %d\n", i, *(arr + i));
	}
	printf("\n");
}

void function_to_show_array(int *array) {
	printf("printing array inside main function:-\n");
	for (size_t i = 0; i < LENGTH; ++i) {
		printf("%d: %d\n", i, *(array + i));
	}
	printf("\n");
}

int main(int argc, char **argv) {
	int arr[LENGTH] = {0, 1, 2, 3, 4};
	// int *array = {5, 6, 7, 8, 9};
	int arra[LENGTH] = {5, 6, 7, 8, 9};
	int *array = arra;

	printf("printing arr inside main function:-\n");
	for (size_t i = 0; i < LENGTH; ++i) {
		printf("%d: %d\n", i, *(arr + i));
	}
	printf("\n");

	function_to_show_arr(arr);

	printf("printing array inside main function:-\n");
	for (size_t i = 0; i < LENGTH; ++i) {
		printf("%d: %d\n", i, *(array + i));
	}
	printf("\n");

	function_to_show_array(array);

	return 0;
}
