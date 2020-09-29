// functions to used in merge sorting in recursion

void merge(int *, int , int, int);

void mergesort(int *arr, int low, int high) {
	// high is SIZE - 1
	if (low < high) {
		int mid = (low + high) / 2;
		mergesort(arr, low, mid);
		mergesort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}


void merge(int *arr, int low, int mid, int high) {
	int start = low;
	int extra[high - low + 1];  // temporary array
	int walk = 0;
	int middle = mid;

	// compare and put elements in temp array till one is finished
	while ((low <= middle) && (mid + 1 <= high)) {
		if (*(arr + low) < *(arr + mid + 1)) {
			*(extra + walk++) = *(arr + low++);
		}
		else {
			*(extra + walk++) = *(arr + mid++ + 1);
		}
	}

	// put the rest of the elements in temporary array
	while (low <= middle) {
		*(extra + walk++) = *(arr + low++);
	}
	while (mid + 1 <= high) {
		*(extra + walk++) = *(arr + mid++ + 1);
	}

	// copy the element of extra back to arr
	for (int i = 0; i < walk; ++i) {
		*(arr + start++) = *(extra + i);
	}
}
