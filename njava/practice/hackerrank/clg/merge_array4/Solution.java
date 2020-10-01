// Merge array

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class Solution {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		//List<Integer> arr1 = new ArrayList<Integer>();
		//List<Integer> arr2 = new ArrayList<Integer>();

		System.out.println("Enter the space seperated numbers for both array");
		String forArr1 = scan.nextLine();
		String forArr2 = scan.nextLine();

		int[] arr1 = Arrays.stream(forArr1.split("\\s")).mapToInt(Integer::parseInt).toArray();
		int[] arr2 = Arrays.stream(forArr2.split("\\s")).mapToInt(Integer::parseInt).toArray();

		List<Integer> temp = new ArrayList<Integer>();
		//int[] newArr = (arr1.length > arr2.length) ? new int[arr1.length] : new int[arr2.length];

		for (int ele1: arr1) {
			for (int ele2: arr2) {
				if (ele1 * 2 == ele2) {
					temp.add(ele1);
				}
			}
		}
		//newArr = temp.toArray();
		int[] newArr = temp.stream().mapToInt(i->i).toArray();
		System.out.println("printing new arr:");
		for (int ele: newArr) {
			System.out.println(ele);
		}
		scan.close();
	}
}



		//while (scan.hasNextInt()) {
			//arr1.add(scan.nextInt());
		//}

		//scan.nextLine();

		//while (scan.hasNextInt()) {
			//arr2.add(scan.nextInt());
		//}

		//System.out.println("print content 1");
		//for (int ele: arr1) {
			//System.out.println(ele);
		//}

		//System.out.println("print content 2");
		//for (int ele: arr2) {
			//System.out.println(ele);
		//}

		//int[] arr1 = new Integer[(forArr1.length() + 1) / 2];
		//int[] arr2 = new Integer[(forArr2.length() + 1) / 2];


		//int[] newArr;
		//newArr = (forArr1.length() > forArr2.length()) ? new int[forArr1.length()] : new int[forArr2.length()];

		/*int count = 0;
		for (int i = 0; i < forArr1.length(); ++i) {
			for (int j = 0; j < forArr2.length(); ++j) {
				if (forArr1.charAt(i) != ' ' && forArr2.charAt(j) != ' ') {
					int fval = Character.getNumericValue(forArr1.charAt(i));
					int sval = Character.getNumericValue(forArr2.charAt(i));
					System.out.println("Inside first if, fval: " + fval + ", sval: " + sval);
					if (fval * 2 == sval) {
						System.out.println("Entering ele: " + fval);
						newArr[count++] = fval;
					}
				}
			}
		}

		System.out.println("Printing array:");*/
		//for (int ele: newArr) {
			//System.out.println(ele);
		//}
		//scan.close();
