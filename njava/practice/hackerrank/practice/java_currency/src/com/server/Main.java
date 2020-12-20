package com.server;

import java.util.Scanner;
import java.util.Locale;
import java.text.NumberFormat;

public class Main {
	public static void main(String ...args) {
		Scanner scan = new Scanner(System.in);
		double payment = scan.nextDouble();
		scan.close();

		NumberFormat usFormat = NumberFormat.getCurrencyInstance(Locale.US);
		NumberFormat inFormat = NumberFormat.getCurrencyInstance(new Locale("en", "IN"));
		NumberFormat chFormat = NumberFormat.getCurrencyInstance(Locale.CHINA);
		NumberFormat frFormat = NumberFormat.getCurrencyInstance(Locale.FRANCE);
		String us = usFormat.format(payment);
		String india = inFormat.format(payment);
		String china = chFormat.format(payment);
		String france = frFormat.format(payment);
		System.out.println("US: " + us);
		System.out.println("India: " + india);
		System.out.println("China: " + china);
		System.out.println("France: " + france);
	}
}