public class SharedDigit {
	public static void main(String args[]) {
		System.out.println("For 12, 23: " + hasSharedDigit(12, 23));
		System.out.println("For 9, 99: " + hasSharedDigit(9, 99));
		System.out.println("For 15, 55: " + hasSharedDigit(15, 55));
		System.out.println("For 12, 13: " + hasSharedDigit(12, 13));
	}

	// had to do this without use of array
	public static boolean hasSharedDigit(int num1, int num2) {
		if ((num1 >= 10 && num1 <= 99) && (num2 >= 10 && num2 <= 99)) {
			int count = 0;
			int remainder1 = 0, remainder2 = 0;
			while (num1 > 0) {
				remainder1 = num1 % 10;
				num1 /= 10;
				int numberbak = num2;
				while (numberbak > 0) {
					remainder2 = numberbak % 10;
					numberbak /= 10;
					if (remainder1 == remainder2) {
						return true;
					}
				}
			}
		}
		return false;
	}
}
