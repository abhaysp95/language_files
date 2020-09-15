// building max heap
// eg., turning 1, 12, 9, 5, 6, 10 to 12, 6, 10, 5, 1, 9

#include <stdio.h>
#define SIZE 6

void heapify(int *, int);
void swap(int *, int *);

int main(int argc, char **argv) {
	int arr[SIZE];
	printf("Enter the elements of array: ");
	for (int i = 0; i < SIZE; ++i) {
		scanf("%d", (arr + i));
	}

	// Building heap(rearranging array)
	for (int i = SIZE / 2 - 1; i >= 0; --i) {
		heapify(arr, i);
		/*printf("%d time: ", i);*/
		/*for (int j = 0; j < SIZE; ++j) {*/
			/*printf("%d\t", *(arr + j));*/
		/*}*/
		/*printf("\n");*/
	}
	/*heapify(arr, 2);*/
	printf("Printing Max heap attained: \n");
	for (int j = 0; j < SIZE; ++j) {
		printf("%d\n", *(arr + j));
	}
	return 0;
}

void heapify(int *ar, int index) {
	// get the childs
	int largest = index;  // let parent is biggest
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	// compare if left is bigger than parent
	if (left < SIZE && *(ar + left) > *(ar + largest)) {
		largest = left;
	}

	// compare if right is bigger than left or parent(one we got from above)
	if (right < SIZE && *(ar + right) > *(ar + largest)) {
		largest = right;
	}
	if (largest != index) {
		swap (ar + index, ar + largest);
		heapify(ar, largest);
	}
}

void swap (int *a, int *b) {
	/*printf("Element got for swapping %d and %d\n", *a, *b);*/
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
	/*printf("Element after for swapping %d and %d\n", *a, *b);*/
}
