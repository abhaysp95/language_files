// Merge array

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Method1 {
	public void operation() {
		Scanner scan = new Scanner(System.in);

		System.out.println("Enter the space seperated numbers for both array");
		String forArr1 = scan.nextLine();
		String forArr2 = scan.nextLine();

		int[] arr1 = Arrays.stream(forArr1.split("\\s")).mapToInt(Integer::parseInt).toArray();
		int[] arr2 = Arrays.stream(forArr2.split("\\s")).mapToInt(Integer::parseInt).toArray();

		List<Integer> temp = new ArrayList<Integer>();

		for (int ele1: arr1) {
			for (int ele2: arr2) {
				if (ele1 * 2 == ele2) {
					temp.add(ele1);
				}
			}
		}
		int[] newArr = temp.stream().mapToInt(i->i).toArray();
		System.out.println("printing new arr:");
		for (int ele: newArr) {
			System.out.println(ele);
		}
		scan.close();
	}
}

class Method2 {

	private int[] strToInt(String[] strArr) {
		int[] arr = new int[strArr.length];
		int count = 0;
		for (String str: strArr) {
			arr[count++] = Integer.parseInt(str);
		}
		return arr;
	}

	private void printArr(int[] arr, int filled) {
		//System.out.println("Recieved, filled: " + filled);
		System.out.println();
		System.out.print("[ ");
		int count = 0;
		for (int ele: arr) {
			count++;
			if (count == filled) {
				break;
			}
			System.out.print(ele + ", ");
		}
		System.out.print(arr[--count] + " ]\n");
	}

	public void operation() {
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the space seperated numbers for both array: ");
		String str1 = scan.nextLine();
		String str2 = scan.nextLine();
		String[] strArr1 = str1.split("\\s");
		String[] strArr2 = str2.split("\\s");
		int[] intArr1 = strToInt(strArr1);
		int[] intArr2 = strToInt(strArr2);

		int[] intArr3 = intArr1.length > intArr2.length ?
			new int[intArr1.length] :
			new int[intArr2.length];
		// if first one have element whose double exist in second one
		int count = 0;
		for (int ele1: intArr1) {
			for (int ele2: intArr2) {
				if (ele1 * 2 == ele2) {
					//System.out.println("Filling: " + ele1);
					intArr3[count++] = ele1;
				}
			}
		}
		// print the arr
		printArr(intArr3, count);
	}
}

public class Solution {
	public static void main(String[] args) {
		//Method1 m1 = new Method1();
		Method2 m2 = new Method2();
		m2.operation();
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
