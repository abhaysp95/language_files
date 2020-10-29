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
		for (int j = 0; j < this.arr.length; ++j) {
			int min = this.arr[j];
			int minIndex = j;
			for (int i = j + 1; i < this.arr.length; ++i) {
				if (min > this.arr[i]) {
					min = this.arr[i];
					minIndex = i;
				}
			}
			if (j != minIndex) {
				int temp = this.arr[j];
				this.arr[j] = min;
				this.arr[minIndex] = temp;
			}
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
			int min = this.arr[start];
			int minIndex = start;
			for (int i = start + 1; i < this.arr.length; ++i) {
				if (min > this.arr[i]) {
					min = this.arr[i];
					minIndex = i;
				}
			}
			if (start != minIndex) {
				int temp = this.arr[start];
				this.arr[start] = min;
				this.arr[minIndex] = temp;
			}
			sort(++start);
		}
	}
}

class Recursive {
	private int[] arr;

	Recursive(int[] arr) {
		this.arr = arr;
	}

	int[] getArr() {
		return this.arr;
	}

	void sort(int start) {
		if (start < this.arr.length) {
			int  minIndex = start;
			minIndex = findMin(start + 1, this.arr[start], start);
			// System.out.println("Got minIndex: " + minIndex + ", value: " + this.arr[minIndex]);
			if (start != minIndex) {
				int temp = this.arr[start];
				this.arr[start] = arr[minIndex];
				this.arr[minIndex] = temp;
			}
			sort(++start);
		}
	}

	private int findMin(int start, int min, int minIndex) {
		if (start == this.arr.length) {
			return minIndex;
		}
		if (min > this.arr[start]) {
			min = this.arr[start];
			minIndex = start;
		}
		return findMin(++start, min, minIndex);
	}
}

public class Solution {
	public static void main(String[] args) {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		try {
			int[] arr = new int[5];
			for (int i = 0; i < arr.length; ++i) {
				arr[i] = Integer.parseInt(bf.readLine());
			}

			int[] temp = arr;

			Iterative iter = new Iterative(arr);
			iter.sort();
			System.out.println("Sorted(with Iteration): \n" + Arrays.toString(arr));

			arr = temp;
			OneRecOneIter oroi = new OneRecOneIter(arr);
			oroi.sort(0);
			System.out.println("Sorted(One Recursion, One Iteration): \n" + Arrays.toString(arr));

			arr = temp;
			Recursive rec = new Recursive(arr);
			rec.sort(0);
			// arr = rec.getArr();
			System.out.println("Sorted(Recursion): \n" + Arrays.toString(arr));
		}
		catch (IOException ie) {
			System.out.println("IOException");
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("Unaccessible block: " + aie);
		}
	}

	public static void print(int[] arr) {
		for (int e: arr) {
			System.out.println(e);
		}
	}
}

/* Inputs:
5
2
1
4
8
*/
