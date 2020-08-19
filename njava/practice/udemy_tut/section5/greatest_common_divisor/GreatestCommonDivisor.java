public class GreatestCommonDivisor {
	public static void main(String args[]) {
		System.out.println("GCD of 25, 15 is: " + getGreatestCommonDivisor(25, 15));
		System.out.println("GCD of 12, 30 is: " + getGreatestCommonDivisor(12, 30));
		System.out.println("GCD of 9, 18 is: " + getGreatestCommonDivisor(9, 18));
		System.out.println("GCD of 81, 153 is: " + getGreatestCommonDivisor(81, 153));
	}

	public static int getGreatestCommonDivisor(int num1, int num2) {
		if (num1 < 10 || num2 < 10) {
			return -1;
		}
		int divisor = 1;
		int isDivided = 0;
		int get_min = num1 > num2 ? num2 : num1;
		while (divisor <= get_min) {
			if ((num1 % divisor == 0) && (num2 % divisor == 0)) {
				isDivided = divisor;
			}
			++divisor;
		}
		return isDivided;
	}
}
