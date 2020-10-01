import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		/*int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();

		System.out.println(a);
		System.out.println(b);
		System.out.println(c);*/
		Scanner in=new Scanner(System.in);
		int rounds = 0;
		while (rounds < 1 || rounds > 3) {
			System.out.print("How many rounds? ");
			if (in.hasNextInt()) {
				rounds = in.nextInt();
			} else {
				System.out.println("Invalid input. Please try again.");
				in.next();
				System.out.println();
			}
			// Clear buffer
		}
		System.out.print(rounds+" rounds.");
	}
}
