// get the digit sum

public class Main {
	public static void main(String args[]) {
		long num = 125L;
		int result = sumDigits(num);
		System.out.println("Sum of digits of " + num + " is: " + result);
		System.out.println("Sum of -1: " + sumDigits(-1));
		System.out.println("Sum of 783492349023 is: " + sumDigits(783492349023L));
	}

	public static int sumDigits(long number) {
		if (number < 10) {
			return -1;
		}
		long remainder = 0;
		int sum = 0;  // sum ain't going to be that big
		while (number > 0) {
			remainder = number % 10;
			number /= 10;
			sum += remainder;
		}
		return sum;
	}
}
