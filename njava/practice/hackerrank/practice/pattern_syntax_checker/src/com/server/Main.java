package com.server;

import java.util.regex.*;
import java.util.Scanner;

public class Main {

	public static boolean checkPattern(String pattern) {
		try {
			Pattern compiledPattern = Pattern.compile(pattern);
			// not needed
			/* Matcher matcher = compiledPattern.matcher("demo"); */
			return true;
		}
		catch (PatternSyntaxException pse) {
			return false;
		}
	}

	public static void main(String ...args) {
		Scanner sc = new Scanner(System.in);
		int testCases = sc.nextInt();
		sc.nextLine();
		while (testCases-- > 0) {
			String pattern = sc.nextLine();
			System.out.println(Main.checkPattern(pattern) ? "Valid" : "Invalid");
		}
	}
}