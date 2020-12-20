package com.raytracer;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
	public static void main(String ...args) {
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			try {
				String[] firstMultipleInput = bf.readLine().replaceAll("\\s+$", "").split(" ");
				int month = Integer.parseInt(firstMultipleInput[0]);
				int day = Integer.parseInt(firstMultipleInput[1]);
				int year = Integer.parseInt(firstMultipleInput[2]);

				String res = Result.findDayNew(month, day, year);
				System.out.println(res);
			}
			finally {
				bf.close();
			}
		}
		catch (IOException ioe) {
			System.out.println("Some IOException: " + ioe.getMessage());
		}
	}
}