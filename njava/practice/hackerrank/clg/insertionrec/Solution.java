import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

class Iterative {
	private int[] arr;

	Iterative(int[] arr) {
		this.arr = arr;
	}

	void sort() {
		for (int i = 1; i < this.arr.length; ++i) {
			int key = this.arr[i];
			int j = i - 1;
			while (j >= 0 && this.arr[j] > key) {
				this.arr[j + 1] = this.arr[j];
				j -= 1;
			}
			this.arr[j + 1] = key;
		}
	}
}


class OneRecOneIter {
	private int[] arr;

	OneRecOneIter(int[] arr) {
		this.arr = arr;
	}

	void sort(int start) {
		if (start < this.arr.length) {
			int key = this.arr[start];
			int j = start - 1;
			while (j >= 0 && this.arr[j] > key) {
				this.arr[j + 1] = this.arr[j];
				j--;
			}
			this.arr[j + 1] = key;
			sort(++start);
		}
	}
}


class Recursion {
	private int[] arr;

	Recursion(int[] arr) {
		this.arr = arr;
	}

	void sort(int start) {
		if (start < this.arr.length) {
			int key = this.arr[start];
			int j = start - 1;
			j = innerSort(j, key);
			this.arr[j + 1] = key;
			sort(++start);
		}
	}

	private int innerSort(int j, int key) {
		if (j < 0 || this.arr[j] < key) {
			return j;
		}
		this.arr[j + 1] = this.arr[j];
		return innerSort(--j, key);
	}
}


public class Solution {
	public static void main(String[] args) {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int[] arr = new int[5];
		try {
			String[] input = bf.readLine().split("\\s+");
			if (input.length > 5) { return; }
			for (int i = 0; i < input.length; ++i) {
				arr[i] = Integer.parseInt(input[i]);
			}

			int[] temp = arr;

			Iterative iter = new Iterative(arr);
			iter.sort();
			System.out.println("Sorted(with Iteration): " + Arrays.toString(arr));

			arr = temp;
			OneRecOneIter oroi = new OneRecOneIter(arr);
			oroi.sort(1);
			System.out.println("Sorted(with Iteration): " + Arrays.toString(arr));

			arr = temp;
			Recursion rec = new Recursion(arr);
			rec.sort(1);
			System.out.println("Sorted(with Iteration): " + Arrays.toString(arr));
		}
		catch (IOException ie) {
			System.out.println("Some IOException");
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("Unaccessible block: " + aie);
		}
	}

	public static void print(int[] arr) {
		for (int e: arr) {
			System.out.print(e + " ");
		}
	}

	public static void insRecSort(int[] arr, int start, int n) {
		if (start >= n) {
			return;
		}
		int key = arr[start];
		int j = start - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		insRecSort(arr, start + 1, n);
	}
}

/* 5 2 1 4 8 */
