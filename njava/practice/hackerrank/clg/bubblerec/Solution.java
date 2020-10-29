import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Solution {
	public static void main(String[] args) {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int[] arr = new int[5];
		try {
			for (int i = 0; i < arr.length; ++i) {
				arr[i] = Integer.parseInt(bf.readLine());
			}
			bubRecSort1(arr, 0);
		}
		catch (IOException ie) {
			System.out.println("Some IOException");
		}
		for (int e: arr) {
			System.out.println(e);
		}
	}

	public static void bubRecSort1(int[] arr, int index) {
		if (index < arr.length) {
			System.out.println("Here");
			bubRecSort2(arr, 1, index);
			bubRecSort1(arr, ++index);  /** don't use index++ */
		}
	}

	public static void bubRecSort2(int[] arr, int index, int end) {
		System.out.println("index: " + index + ", end: " + end + ", arr.length: " + arr.length);
		if (index < arr.length - end) {
			if (arr[index - 1] > arr[index]) {
				int temp = arr[index];
				arr[index] = arr[index - 1];
				arr[index - 1] = temp;
			}
			bubRecSort2(arr, ++index, end);
		}
	}
}
