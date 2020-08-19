// PerfectNumber is a positive integer which is equal to the sum of its all proper positive divisors
// Positive divisors are the positive integers that fully divide the PerfectNumber excluding PerfectNumber itself

public class PerfectNumber {
	public static void main(String args[]) {
		System.out.println("Check if PerfectNumber for 6: " + isPerfectNumber(6));
		System.out.println("Check if PerfectNumber for 28: " + isPerfectNumber(28));
		System.out.println("Check if PerfectNumber for 5: " + isPerfectNumber(5));
		System.out.println("Check if PerfectNumber for -1: " + isPerfectNumber(-1));
	}

	public static boolean isPerfectNumber(int number) {
		if (number < 1) {
			return false;
		}
		int divisor = 1;
		int sum = 0;
		while (divisor <= number/2) {
			if (number % divisor == 0) {
				sum += divisor;
			}
			++divisor;
		}
		if (number == sum) {
			return true;
		}
		return false;
	}
}
