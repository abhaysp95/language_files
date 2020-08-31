// find the minimum element from the array

import java.util.Arrays;
import java.util.Scanner;

class minElementChallange {

	private int[] arr;

	// no need for constructor
	//minElementChallange(int ...arr) {
		//this.arr = arr;
	//}

	private static Scanner scan = new Scanner(System.in);

	int[] getElements() {
		System.out.println("Enter the number of elements to input:\r");
		// Scanner scan = new Scanner(System.in);  // used as private static for whole class
		int number = scan.nextInt();
		this.arr = new int[number];
		for (int i = 0; i < number; ++i) {
			this.arr[i] = scan.nextInt();
		}
		return arr;
	}

	int findMinElement() {
		int min = this.arr[0];
		// or you can just set it to Integer.MAX_VALUE;
		for (int i = 1; i < this.arr.length; ++i) {
			if (this.arr[i] < min) {
				min = this.arr[i];
			}
		}
		return min;
	}
}

class Main {
	public static void main(String[] args) {
		minElementChallange obj = new minElementChallange();
		int[] valuesArray = obj.getElements();
		int min = obj.findMinElement();
		System.out.println("Min element in array "
				+ Arrays.toString(valuesArray)
				+ " is: " + min);
	}
}
