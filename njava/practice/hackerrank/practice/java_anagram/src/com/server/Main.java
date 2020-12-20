package com.server;

import java.util.Scanner;

public class Main {

	public static boolean isAnagram(String a, String b) {
		if (a.length() != b.length()) {
			return false;
		}
		int[] countA = new int[26];
		int[] countB = new int[26];
		char[] charA = a.toLowerCase().toCharArray();
		char[] charB = b.toLowerCase().toCharArray();
		for (int i = 0; i < charA.length; ++i) {
			countA[charA[i] - 97]++;
			countB[charB[i] - 97]++;
		}
		for (int i = 0; i < countA.length; ++i) {
			if (countA[i] != countB[i]) {
				return false;
			}
		}
		return true;
	}

	public static void main(String ...args) {
		Scanner scan = new Scanner(System.in);
		String a = scan.next();
		String b = scan.next();
		scan.close();
		boolean ret = isAnagram(a, b);
		System.out.println( (ret) ? "Anagrams" : "Not Anagrams");
	}
}