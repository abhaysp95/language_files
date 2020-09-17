//Given two arrays, both having String elements, write a java program to create
//a new string as per the rule given below: The first element in array1 should
//be merged with last element in array2, second element in array1 should be
//merged with second last element in array2 and so on. If an element in
//array1/array2 is None, then the corresponding element in the other array
//should be kept as it is in the merged array

//Input Format

//Line 1 accepts integer M, length of first array Line 2 accepts integer N,
//length of second array Line 3,space separated M elements for first array Line
//4,space separated N elements for first array


import java.util.Scanner;


class MergeArray {
	String[] firstArr;
	String[] secondArr;
	String[] thirdArr;

	MergeArray(String[] firstArr, String[] secondArr) {
		this.firstArr = firstArr;
		this.secondArr = secondArr;
		if (firstArr.length < secondArr.length) {
			this.thirdArr = new String[secondArr.length];
		}
		else {
			this.thirdArr = new String[firstArr.length];
		}
	}

	void getMergedArray() {
		//System.out.println("First: " + this.firstArr);
		//System.out.println("First: " + this.secondArr);
		// input successful
		/*System.out.println("First");
		for (int i = 0; i < firstArr.length; ++i) {
			System.out.println(firstArr[i]);
		}
		System.out.println("Second");
		for (int i = 0; i < firstArr.length; ++i) {
			System.out.println(secondArr[i]);
		}*/

		int i = 0;
		int j = secondArr.length - 1;
		int step = 0;
		/* don't use (... == "None") here, as == will compare the reference of
		 * string object, in this case with firstArr[index] or secondArr[index]
		 * but use 'equals()' method which will compare the value of the string
		 * method like in this case of firstArr[index]'s or secondArr[index]'s
		 * value */
		while ((i < firstArr.length) && (j >= 0)) {
			if (firstArr[i].equals("None")) {
				//System.out.println("inside if");
				thirdArr[step++] = "" + secondArr[j--];
				i++;
			}
			else if (secondArr[j].equals("None")) {
				//System.out.println("inside else if");
				thirdArr[step++] = firstArr[i++] + "";
				j--;
			}
			else {
				//System.out.println("inside else");
				thirdArr[step++] = firstArr[i++] + secondArr[j--];
			}
		}
		// get rest element
		while (i < firstArr.length) {
			thirdArr[step++] = firstArr[i++];
		}
		while (j >= 0) {
			thirdArr[step++] = secondArr[j--];
		}

		//System.out.println("Printing new Array element: ");
		int k = 0;
		for (k = 0; k < step - 1; ++k) {
			System.out.print(thirdArr[k] + " ");
		}
		System.out.print(thirdArr[k++]);
		System.out.println();
	}

	/*void compare(String s) {
		if (s.equals("None")) {
			System.out.println("yes");
		}
		else {
			System.out.println("no");
		}
	}*/
}




public class Solution {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int fSize = scan.nextInt();
		scan.nextLine();
		int sSize = scan.nextInt();
		scan.nextLine();
		String[] fArr = new String[fSize];
		String[] sArr = new String[sSize];
		String firstString = scan.nextLine();
		String secondString = scan.nextLine();
		fArr = firstString.split("\\s+");
		sArr = secondString.split("\\s+");
		/*for (int i = 0; i < fSize; ++i) {
			fArr[i] = scan.next();
		}*/
		/*for (int i = 0; i < sSize; ++i) {
			fArr[i] = scan.nextLine();
		}*/
		MergeArray ob = new MergeArray(fArr, sArr);
		ob.getMergedArray();
	}
}
