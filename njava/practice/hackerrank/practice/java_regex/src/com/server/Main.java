package com.server;

import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Scanner;

//String block = "(\\d{1,2}|(0|1)\\d{2}|2[0-4]\\d|25[0-5])";
class MyRegex {
	String block = "([0-9]{1}|[0-9]{2}|[0-1][0-9]{2}|2[0-4][0-9]|2[0-5]{2})";
	String pattern = "^" + block + "\\." + block + "\\." + block + "\\." + block + "$";
}

public class Main {
	public static void main(String ...args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			String IP = in.next();
			System.out.println(IP.matches(new MyRegex().pattern));
		}
	}
}