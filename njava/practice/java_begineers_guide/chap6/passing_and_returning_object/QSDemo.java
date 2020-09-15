// Quick Sort(character array)

class QuickSort {
	// setup call to actual quick sort public_method
	static void qsort(char items[]) {
		qs(items, 0, items.length - 1);
	}

	private static void qs(char[] items, int left, int right) {
		int i = left, j = right;
		char x, y;

		// although you can choose any item as middle but it's better if it's middle
		x = items[(left + right) / 2];
		do {
			while ((items[i] < x) && (i < right)) {
				i++;
			}
			while ((x > items[j]) && (j > left)) {
				j--;
			}

			if (i <= j) {
				y = items[i];
				items[i] = items[j];
				items[j] = y;
			}
		} while (i <= j);

		if (left < j) {
			qs(items, left, j);
		}
		if (i < right) {
			qs(items, i, right);
		}
	}
}

class QSDemo {
	public static void main(String[] args) {
		char[] a = { 'd', 'x', 'a', 'r', 'p', 'j', 'i' };
		System.out.println("Original array: ");
		for (int i = 0; i < a.length; ++i) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
		// sort the array
		QuickSort.qsort(a);
		System.out.println("Sorted array: ");
		for (int i = 0; i < a.length; ++i) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
	}
}
