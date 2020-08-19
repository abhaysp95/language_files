public class NumberToWords {
	public static void main(String args[]) {
		System.out.println("For 123: ");
		numberToWords(123);
		System.out.println("--------------------------");
		System.out.println("For -12: ");
		numberToWords(-12);
		System.out.println("--------------------------");
		System.out.println("For 1000: ");
		numberToWords(1000);
		System.out.println("--------------------------");
		System.out.println("For 1010: ");
		numberToWords(1010);
		System.out.println("\n--------------------------\n");
		System.out.println("reverse of -12: " + reverse(-12));
	}

	public static void numberToWords(int number) {
		if (number < 0) {
			System.out.println("Invalid Value");
		}
		else {
			int reverseNum = reverse(number);
			int getCount = getDigitCount(number);
			int count = 0;
			// System.out.println("Got reverseNum: " + reverseNum);
			int remainder = 0;
			while (count != getCount) {
				remainder = reverseNum % 10;
				switch (remainder) {
					case 0:
						System.out.println("Zero");
						break;
					case 1:
						System.out.println("One");
						break;
					case 2:
						System.out.println("Two");
						break;
					case 3:
						System.out.println("Three");
						break;
					case 4:
						System.out.println("Four");
						break;
					case 5:
						System.out.println("Five");
						break;
					case 6:
						System.out.println("Six");
						break;
					case 7:
						System.out.println("Seven");
						break;
					case 8:
						System.out.println("Eight");
						break;
					case 9:
						System.out.println("Nine");
						break;
				}
				reverseNum /= 10;
				++count;
			}
		}
	}

	public static int reverse(int number) {
		int numberBak = number;
		if (number < 0) {
			number = -number;
		}
		int remainder = 0, reverseNum = 0;
		while (number > 0) {
			remainder = number % 10;
			number /= 10;
			reverseNum = reverseNum * 10 + remainder;
		}
		reverseNum = numberBak < 0 ? -reverseNum : reverseNum;
		return reverseNum;
	}

	public static int getDigitCount(int number) {
		if (number < 0) {
			return -1;
		}
		if (number == 0) {
			return 1;
		}
		int count = 0;
		while (number > 0) {
			count++;
			number /= 10;
		}
		return count;
	}
}
