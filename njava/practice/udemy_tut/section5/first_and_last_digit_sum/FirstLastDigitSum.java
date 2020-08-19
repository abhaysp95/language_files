public class FirstLastDigitSum {
	public static void main(String args[]) {
		System.out.println("Digit count for 1024: " + sumFirstAndLastDigit(1024));
		System.out.println("Digit count for 5: " + sumFirstAndLastDigit(5));
		System.out.println("Digit count for 0: " + sumFirstAndLastDigit(0));
		System.out.println("Digit count for 257: " + sumFirstAndLastDigit(257));
	}

	public static int sumFirstAndLastDigit(int number) {
		if (number < 0) {
			return -1;
		}
		int numberBak = number;
		int sum = 0;
		int digitcount = 1;
		while (number > 9) {
			digitcount *= 10;
			number /= 10;
		}
		sum = numberBak / digitcount + numberBak % 10;
		return sum;
	}
}
