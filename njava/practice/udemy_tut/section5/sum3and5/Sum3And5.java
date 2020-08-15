public class Sum3And5 {
	public static void main(String args[]) {
		int sum = 0, count = 0;
		for (int i = 1; i <= 1000; ++i) {
			if (i % 3 == 0 && i % 5 == 0) {
				System.out.println("Number found: " + i);
				sum += i;
				count++;
			}
			if (count == 5) {
				break;
			}
		}
		System.out.println("--------------------------------");
		System.out.println("Sum of 5 numbers found: " + sum);
	}
}
