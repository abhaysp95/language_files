// main file

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/sortutil.h"

int main(int argc, char **argv) {
	int n;
	scanf("%d", &n);

	char** arr;
	// initialize 2d array
	arr = (char**)malloc(n * sizeof(char*));

	for (int i = 0; i < n; ++i) {
		// initialize array to take input
		*(arr + i) = malloc(1024 * sizeof(char));
		scanf("%s", *(arr + i));
		// resize to the input string size, to not waste space
		*(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
	}
	printf("\nyou entered:\n");
	for (int i = 0; i < n; ++i) {
		printf("%s\n", arr[i]);
	}
	printf("\n");
	printf("\n---------------\n");

	printf ("\n------------------\n\n");

	string_sort(arr, n, lexicographic_sort);
	for (int i = 0; i < n; ++i) {
		/*printf("%s%c\n", arr[i], i == n - 1 ? '\n' : ' ');*/
		printf("%s\n", arr[i]);
	}
	printf("\n---------------\n");

	string_sort(arr, n, lexicographic_sort_reverse);
	for (int i = 0; i < n; ++i) {
		/*printf("%s%c", arr[i], i == n - 1 ? '\n' : ' ');*/
		printf("%s\n", arr[i]);
	}
	printf("\n---------------\n");

	string_sort(arr, n, sort_by_length);
	for (int i = 0; i < n; ++i) {
		/*printf("%s%c", arr[i], i == n - 1 ? '\n' : ' ');*/
		printf("%s\n", arr[i]);
	}
	printf("\n---------------\n");

	string_sort(arr, n, sort_by_number_of_distinct_characters);
	for (int i = 0; i < n; ++i) {
		/*printf("%s%c", arr[i], i == n - 1 ? '\n' : ' ');*/
		printf("%s\n", arr[i]);
	}
	printf("\n---------------\n");

	free_arr(arr, n);
	printf("\nMemory freed\n");

    return 0;
}