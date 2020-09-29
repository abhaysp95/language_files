package Anagram_solution;

import java.util.Scanner;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.ArrayList;

class Anagram {
	private List<Integer> countList;

	Anagram() {
		countList = new ArrayList<Integer>();
	}

	private String sort(String ele) {
		char[] carr = ele.toCharArray();
		Arrays.sort(carr);
		return new String(carr);
	}

	private boolean compare(String ele1, String ele2) {
		if (this.sort(ele1).equals(this.sort(ele2))) {
			return true;
		}
		return false;
	}

	public List<Integer> getCount(List<String> dict, List<String> q) {
		for (String element: q) {
			int count = 0;
			for (String ele: dict) {
				if (element.length() == ele.length()) {
					System.out.println("first comp: " + element);
					System.out.println("second comp: " + ele);
					if (this.compare(element, ele)) {
						System.out.println("passed");
						count++;
					}
				}
			}
			this.countList.add(count);
		}
		return this.countList;
	}
}

public class Solution {
	public static void main(String[] args) {
		// currently having static dictionary and query
		Scanner scan = new Scanner(System.in);
		List<String> dictionary = new ArrayList<String>();
		List<String> query = new ArrayList<String>();
		List<Integer> countList;

		int dictLength;
		System.out.println("Enter length of dictionary:");
		try {
			dictLength = scan.nextInt();
			scan.nextLine();
		}
		catch (InputMismatchException e) {
			System.out.println("You have to enter count for dictionary");
			return;
		}
		System.out.println("Enter the content for dictionary: ");
		for (int i = 0; i < dictLength; ++i) {
			dictionary.add(scan.nextLine());
		}
		System.out.println("\nYou entered dictionary:");
		System.out.print("{ ");
		for (String ele: dictionary) {
			System.out.print(ele + ", ");
		}
		System.out.print(" }\n");
		scan.nextLine();  // clear out buffer for carriage return
		System.out.println("Enter length of query:");
		int qLength;
		try {
			qLength = scan.nextInt();
		}
		catch (InputMismatchException e) {
			System.out.println("You have to enter count for query");
			return;
		}
		scan.nextLine();
		System.out.println("Enter the content for query: ");
		for (int i = 0; i < qLength; ++i) {
			query.add(scan.nextLine());
		}
		System.out.println("\nYou entered query:");
		System.out.print("{ ");
		for (String ele: query) {
			System.out.print(ele + ", ");
		}
		System.out.print(" }\n");

		Anagram obj = new Anagram();
		countList = obj.getCount(dictionary, query);

		System.out.println("Count of Anagram is: ");
		for (int num: countList) {
			System.out.print(num + "\t");
		}
		System.out.println();
	}
}
