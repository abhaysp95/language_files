/* StringBuffer creates mutable string */

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		StringBuffer sb = new StringBuffer("This is String Buffer");
		System.out.println(sb);

		sb.append(", and this is appended to orignal string");
		System.out.println(sb);

		sb.insert(0, "Hello, ");
		System.out.println(sb);

		sb.delete(0, 7);
		System.out.println(sb);

		StringBuffer sb2 = new StringBuffer("united institute of technology");
		System.out.println(sb2);
		sb2.insert(0, "true ");
		System.out.println(sb2);
		sb2.delete(0, 5);
		sb2.insert(6, " true");
		System.out.println(sb2);
		sb2.delete(6, 11);
		sb2.insert(19, " true");
		System.out.println(sb2);

		Scanner scan = new Scanner(System.in);
		StringBuilder sb3 = new StringBuilder(scan.nextLine());
		StringBuilder oldString = sb3;
		System.out.println(sb3);
		System.out.println(sb3.insert(0, "true "));
		System.out.println(sb3.insert(6, " true"));
		sb3 = oldString;
		System.out.println(sb3.insert(19, " true"));
	}
}
