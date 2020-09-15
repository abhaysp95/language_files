// heap sort(using full_heap_sort.h)

#include <stdio.h>
#include "full_heap_sort.h"

void heap_sort(int *, int);

int main(int argc, char **argv) {
	int array[] = {1, 12, 9, 5, 6, 10};
	int size = sizeof(array) / sizeof(*array);
	printf("Array before: \n");
	for (int i = 0; i < size; ++i) {
		printf("%d\n", *(array + i));
	}
	heap_sort(array, size);
	printf("Array after: \n");
	for (int i = 0; i < size; ++i) {
		printf("%d\n", *(array + i));
	}
	return 0;
}
