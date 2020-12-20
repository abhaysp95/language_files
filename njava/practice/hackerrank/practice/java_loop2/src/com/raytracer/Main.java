package com.raytracer;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String ...args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int i = 0; i < t; ++i) {
			int a = in.nextInt();
			int b = in.nextInt();
			int c = in.nextInt();
			Main.calculateSeries(a, b, c);
		}
		in.close();
	}

	private static void calculateSeries(int a, int b, int c) {
		int[] arr = new int[c];
		for (int i = 1; i <=c; ++i) {
			int sum = a;
			for (int j = 0; j < i; ++j) {
				sum += (int)Math.pow(2, j) * b;
			}
			arr[i-1] = sum;
		}
		Main.printSeries(arr);
	}

	private static void printSeries(int[] arr) {
		for (int num: arr) {
			System.out.print(num + " ");
		}
		System.out.println();
	}
}