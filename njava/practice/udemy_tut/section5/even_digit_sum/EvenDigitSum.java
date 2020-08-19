public class EvenDigitSum {
	public static void main(String args[]) {
		System.out.println("Sum of even digits of number 123456789 is: " + getEvenDigitSum(123456789));
		System.out.println("Sum of even digits of number 252 is: " + getEvenDigitSum(252));
		System.out.println("Sum of even digits of number -22 is: " + getEvenDigitSum(-22));
	}

	public static int getEvenDigitSum(int number) {
		if (number < 0) {
			return -1;
		}
		int sum = 0;
		int remainder = 0;
		while (number > 0) {
			remainder = number % 10;
			number /= 10;
			if (remainder % 2 == 0) {
				sum += remainder;
			}
		}
		return sum;
	}
}
