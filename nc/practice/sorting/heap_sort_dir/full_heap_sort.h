// functions needed for heap sort
// predeclaration of function can be used with header file too, it's necessary if you are using function before it's defined

void swap(int *a, int *b) {
	// it has a problem if *a and *b both are same then it returns 0
	*a += *b;
	*b = *a - *b;
	*a -= *b;
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
		if (*(arr + index) != *(arr + largest)) {
			swap(arr + index, arr + largest);
		}
		heapify(arr, size, largest);
	}
}

void heap_sort(int *arr, int size) {
	// heapify
	for (int i = size / 2 - 1; i >= 0; --i) {
		heapify(arr, size, i);
	}

	// heap sort
	for (int i = size - 1; i >= 0; --i) {
		if (*arr != *(arr + i)) {
			swap (arr, arr + i);
		}
		heapify(arr, i, 0);
	}
}
