package com.server;

import java.util.Scanner;

public class Main {
	public static void main(String ...args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.nextLine();
		s = s.trim();
		if (s.length() > 0 && s.length() < (int)4e5) {
			String[] splittedString = s.split("[\\s@',?!_.]+", 0);
			System.out.println(splittedString.length);
			for (String str: splittedString) {
				System.out.println(str);
			}
		}
		else if (s.length() == 0) {
			System.out.println("0");
		}
		scan.close();
	}
}