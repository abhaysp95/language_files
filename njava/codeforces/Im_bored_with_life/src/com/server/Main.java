package com.server;

import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	private static Scanner scan = new Scanner(System.in);

	public static void main(String ...args) {
		BigInteger numA = scan.nextBigInteger();
		BigInteger numB = scan.nextBigInteger();
		Main obj = new Main();
		BigInteger factA = obj.factorial(numA);
		BigInteger factB = obj.factorial(numB);
		BigInteger got_gcd = obj.getGCD(factA, factB);
		System.out.println("factA: " + factA + ", factB: " + factB);
		System.out.println("GCD: " + got_gcd);
		scan.close();
	}

	public BigInteger factorial(BigInteger num) {
		if (num.compareTo(new BigInteger("1")) == 0) {
			return new BigInteger("1");
		}
		return num.multiply(factorial(num.subtract(new BigInteger("1"))));
	}

	public BigInteger getGCD(BigInteger a, BigInteger b) {
		if (a.remainder(b).compareTo(new BigInteger("0")) == 0) {
			return b;
		}
		BigInteger min = (a.compareTo(b) == 1) ? b : a;
		return getGCD(min, a.remainder(b));
	}
}