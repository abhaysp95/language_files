/* take input and check which type of primitive data type for storing int will be suitable */


/* They are:
   byte, 8-bit signed
   short, 16-bit signed
   int, 32-bit signed
   long, 64-bit signed */

import java.util.Scanner;
import java.lang.Exception;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();

		for (int i = 0; i < t; ++i) {
			try {
				long x = sc.nextLong();
				System.out.println(x + " can be fitted in:");
				if (x >= Byte.MIN_VALUE && x <= Byte.MAX_VALUE) {
					System.out.println("* byte");
					System.out.println("* short");
					System.out.println("* int");
					System.out.println("* long");
				}
				else if (x >= Short.MIN_VALUE && x <= Short.MAX_VALUE) {
					System.out.println("* short");
					System.out.println("* int");
					System.out.println("* long");
				}
				else if (x >= Integer.MIN_VALUE && x <= Integer.MAX_VALUE) {
					System.out.println("* int");
					System.out.println("* long");
				}
				else if (x >= Long.MIN_VALUE && x <= Long.MAX_VALUE) {
					System.out.println("* long");
				}
			}
			catch (Exception e) {
				System.out.println(sc.next() + " can't be fitted anywhere.");
			}
		}
	}
}
