// how heap sort works

/* Since the tree satisfies Max-Heap property, then the largest item is stored at the root node.
Swap: Remove the root element and put at the end of the array and put the last item of tree at vacant place
Remove: Reduce the size of the heap by 1.
Heapify: Heapify the root element again so that we have the highest element at root
Repeat process until all the items are sorted */

#include <stdio.h>
#define SIZE 6

void swap(int *, int *);
void heapify(int *, int, int);

int main(int argc, char **argv) {
	int array[] = {12, 6, 10, 5, 1, 9};

	// operation will be performed to the SIZE - 1 of array
	for (int i = SIZE - 1; i >= 0; --i) {
		swap (array, array + i);
		heapify(array, i, 0);
	}
	printf("printing array after heap sort\n");
	for (int i = 0; i < SIZE; ++i) {
		printf("%d\n", *(array + i));
	}
	return 0;
}

void swap (int * a, int *b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void heapify(int *arr, int size, int index) {
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size && *(arr + left) > *(arr + largest)) {
		largest = left;
	}

	if (right < size && *(arr + right) > *(arr + largest)) {
		largest = right;
	}

	if (largest != index) {
		swap (arr + index, arr + largest);
		heapify(arr, size, largest);
	}
}
