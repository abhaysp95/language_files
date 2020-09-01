// resizing of array

import java.util.Arrays;
import java.util.Scanner;

class NotSoRightWay {

	private static Scanner scan = new Scanner(System.in);
	private static int[] baseArray = new int[10];

	public static void main(String[] args) {
		System.out.println("Enter elements in array: ");
		getInput();
		System.out.println("Array before change:");
		printArray();
		resizeArray();
		System.out.println("length of new baseArray: " + baseArray.length);
		System.out.println("Array after change: ");
		baseArray[10] = 45;
		baseArray[11] = 56;
		printArray();
	}

	public static void getInput() {
		for (int i = 0; i < baseArray.length; ++i) {
			baseArray[i] = scan.nextInt();
		}
	}

	public static void printArray() {
		for (int i = 0; i < baseArray.length; ++i) {
			System.out.println(baseArray[i]);
		}
	}

	public static void resizeArray() {
		int[] orignal = baseArray;
		// changed size from 10 to 12
		baseArray = new int[12];
		System.out.println("orignal length: " + orignal.length);
		// baseArray = Arrays.copyOf(orignal, orignal.length);
		for (int i = 0; i < original.length; ++i) {
			baseArray[i] = original[i];
		}
		System.out.println("length of new baseArray: " + baseArray.length);
	}
}
