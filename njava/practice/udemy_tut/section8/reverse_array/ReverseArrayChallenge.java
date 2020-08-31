// reverse the array elements

import java.util.Scanner;


class ReverseArrayChallenge {
	private static Scanner scan = new Scanner(System.in);
	private static int number;

	public static void main(String[] args) {
		int arr[] = new int[10];
		getElementsInArray(arr);
		printArray(arr);
		reverseArray(arr);
		printArray(arr);
	}

	// make this static, cause non static method can't be called from static(main)
	static void getElementsInArray(int ...arr) {
		System.out.println("Enter the number of elements to enter in array:\r");
		number = scan.nextInt();
		// arr = new int[number];  // initialize the array
		System.out.println("Enter the elements:");
		for (int i = 0; i < number; ++i) {
			arr[i] = scan.nextInt();
		}
	}

	static void printArray(int ...arr) {
		System.out.println("Printing array");
		for (int i = 0; i < number; ++i) {
			System.out.println("#" + i + ": " + arr[i]);
		}
	}

	static void reverseArray(int ...arr) {
		int maxIndex = number - 1;
		int halfIndex = number / 2;
		for (int i = 0; i <= halfIndex; ++i) {
			if (arr[i] != arr[maxIndex - i]) {
				arr[i] += arr[maxIndex - i];
				arr[maxIndex - i] = arr[i] - arr[maxIndex - i];
				arr[i] -= arr[maxIndex - i];
			}
		}
	}
}
