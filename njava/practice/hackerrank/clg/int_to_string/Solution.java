import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		scan.close();

		String s = String.valueOf(n);
		// System.out.println(s);

		if (n == Integer.parseInt(s)) {
			System.out.println("Good Job");
		}
		else {
			System.out.println("Wrong answer");
		}
	}
}
