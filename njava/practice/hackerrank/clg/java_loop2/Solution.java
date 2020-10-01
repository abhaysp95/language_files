import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int t = in.nextInt();
		for (int i = 0; i < t; ++i) {
			int a = in.nextInt();
			int b = in.nextInt();
			int n = in.nextInt();

			int sum = a;
			for (int j = 0; j < n; ++j) {
				int temp = ((int) Math.pow(2, j)) * b;
				sum += temp;
				System.out.print(sum + " ");
			}
			System.out.println();
		}
		in.close();
	}
}
