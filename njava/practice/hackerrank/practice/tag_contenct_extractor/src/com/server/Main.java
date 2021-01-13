package com.server;

import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.Scanner;

public class Main {
	public static void main(String ...args) {
		Scanner in = new Scanner(System.in);
		int testCases = Integer.parseInt(in.nextLine());
		boolean matchFound = false;
		while (testCases-- > 0) {
			String line = in.nextLine();
			//Pattern pattern = Pattern.compile("\\<([\\d\\w\\s]+)\\>(.*)\\<\\/\\1\\>", Pattern.CASE_INSENSITIVE);
			Pattern pattern = Pattern.compile("\\<(.+)\\>([^\\<\\>]+)\\<\\/\\1\\>", Pattern.CASE_INSENSITIVE);
			Matcher matcher = pattern.matcher(line);
			if (matcher.find()) {
				System.out.println(matcher.group(2));
				System.out.println("-----------------");
			}
			else {
				System.out.println("None");
			}
		}
	}
}