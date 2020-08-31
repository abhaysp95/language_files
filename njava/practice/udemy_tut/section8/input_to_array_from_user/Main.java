// get sum and average of array elements

import java.util.Scanner;

public class Main {

	private static Scanner scan = new Scanner(System.in);

	public static void main(String[] args) {
		int[] myIntegers = getIntegers(5);
		// print the array
		System.out.println("Entered numbers in array are:\r");
		for (int i = 0; i < myIntegers.length; ++i) {
			System.out.println(myIntegers[i]);
		}

		// print the average
		double avg = getAverage(myIntegers);
		System.out.println("Average is: " + avg);
	}

	// get the numbers in array
	public static int[] getIntegers(int number) {
		System.out.println("Enter " + number + " numbers:\r");
		int[] values = new int[number];
		for (int i = 0; i < number; ++i) {
			values[i] = scan.nextInt();
		}
		return values;
	}

	public static double getAverage(int ...array) {
		int sum = 0;
		for (int i = 0; i < array.length; ++i) {
			sum += array[i];
		}
		return (double)sum / (double)array.length;
	}
}
