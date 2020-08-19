public class LastDigitChecker {
	public static void main(String args[]) {
		System.out.println("Check for 41, 22, 71: " + hasSameLastDigit(41, 22, 71));
		System.out.println("Check for 23, 32, 42: " + hasSameLastDigit(23, 32, 42));
		System.out.println("Check for 9, 99, 999: " + hasSameLastDigit(9, 99, 999));
	}

	public static boolean isValid(int number) {
		if (number >= 10 && number <= 1000) {
			return true;
		}
		return false;
	}

	public static boolean hasSameLastDigit(int num1, int num2, int num3) {
		if ((!isValid(num1)) || (!isValid(num2)) || (!isValid(num3))) {
			return false;
		}
		int remainder1 = 0, remainder2 = 0, remainder3 = 0;
		remainder1 = num1 % 10;
		remainder2 = num2 % 10;
		remainder3 = num3 % 10;
		if ((remainder1 == remainder2) || (remainder2 == remainder3) || (remainder1 == remainder3)) {
			return true;
		}
		return false;
	}
}
