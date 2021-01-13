package com.server;

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Main {
	/** pattern matching only the repeated words if there's no other word between them */
	private static final String strExample = "Reya is is is the the best player in eye eye game";
	public static void main(String ...args) {
		//Pattern pattern = Pattern.compile("\\w+([0-4]+)\\w+$1\\w+");
		Pattern pattern = Pattern.compile("\\b(\\w+)(\\b\\W+\\b\\1\\b)*", Pattern.CASE_INSENSITIVE);
		Matcher matcher = pattern.matcher(strExample);
		while (matcher.find()) {
			System.out.println("start: " + matcher.start());
			System.out.println("end: " + matcher.end());
			System.out.println("groups: " + matcher.group());
			System.out.println("group count: " + matcher.groupCount());
			System.out.println("group0: " + matcher.group(0) + "group1: " + matcher.group(1) + "group2: " + matcher.group(2));
		}
		Pattern replace = Pattern.compile("\\s+");
		Matcher matcher2 = replace.matcher(strExample);
		System.out.println(matcher2);
		System.out.println(matcher2.replaceAll("\t"));
	}
}