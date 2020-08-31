// sort the array elements in descending order

import java.util.Scanner;

public class Main {

	private static Scanner scan = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.println("Enter the number of elements you want in array: \r");
		int number = scan.nextInt();

		// get the elements
		int[] arrElements = getElements(number);

		// sort and print
		int[] sortedArray = sortElements1(arrElements);
		printElements(sortedArray);
	}

	public static int[] getElements(int number) {
		int[] values = new int[number];
		System.out.println("Enter the " + number + " elements:\r");
		for (int i = 0; i < number; ++i) {
			values[i] = scan.nextInt();
		}
		return values;
	}

	public static void printElements(int ...arrElements) {
		System.out.println("Elements of array are:\r");
		for (int i = 0; i < arrElements.length; ++i) {
			System.out.println("#" + i + ": " + arrElements[i]);
		}
	}

	public static int[] sortElements(int ...arrElements) {
		// sort the elements in descending order
		for (int i = 0; i < arrElements.length; ++i) {
			for (int j = i + 1; j < arrElements.length; ++j) {
				if (arrElements[i] < arrElements[j]) {
					arrElements[i] += arrElements[j];
					arrElements[j] = arrElements[i] - arrElements[j];
					arrElements[i] -= arrElements[j];
				}
			}
		}
		return arrElements;
	}


	// another way of implementing bubble sort can be
	public static int[] sortElements1(int ...arrElements) {
		boolean flag = true;
		while (flag) {
			flag = false;
			for (int i = 0; i < arrElements.length - 1; ++i) {
				if (arrElements[i] < arrElements[i + 1]) {
					arrElements[i] += arrElements[i + 1];
					arrElements[i + 1] = arrElements[i] - arrElements[i + 1];
					arrElements[i] -= arrElements[i + 1];
					flag = true;  // just to be sure check again one time
				}
			}
		}
		return arrElements;
	}
}
