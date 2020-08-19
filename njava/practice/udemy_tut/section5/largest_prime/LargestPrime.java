public class LargestPrime {
	public static void main(String args[]) {
		System.out.println("For 21: " + getLargestPrime(21));
		System.out.println("For 217: " + getLargestPrime(217));
		System.out.println("For 0: " + getLargestPrime(0));
		System.out.println("For 45: " + getLargestPrime(45));
		System.out.println("For -1: " + getLargestPrime(-1));
		System.out.println("For 1: " + getLargestPrime(1));
	}

	// method without using any other method
	public static int getLargestPrime(int number) {
		if (number <= 0) {
			return -1;
		}
		int numberBak = number;
		// first get the factors
		int gotPrime = 0;
		int maxPrime = gotPrime;
		boolean flag = true;
		for (int i = 1; i <= number; ++i) {
			flag = true;
			if (number % i == 0) {
				// System.out.println(i);
				if (i >= 2) {
					for (int j = 2; j <= Math.sqrt(i); ++j) {
						if (i % j == 0) {
							flag = false;
							break;
						}
					}
					if (flag) {
						gotPrime = i;
						if (maxPrime < gotPrime) {
							maxPrime = gotPrime;
						}
					}
				}
			}
		}
		if (gotPrime == 0) {
			return -1;
		}
		return gotPrime;
	}

	public static int getLargestPrime1(int number) {
		if (number <= 0) {
			return -1;
		}
		int numberBak = number;
		// first get the factors
		int gotPrime = 0;
		int maxPrime = gotPrime;
		for (int i = 1; i <= number; ++i) {
			if (number % i == 0) {
				if (ifPrime(i)) {
					// System.out.println("Got Prime: " + i);
					gotPrime = i;
					if (maxPrime < gotPrime) {
						maxPrime = gotPrime;
					}
				}
			}
		}
		return gotPrime;
	}

	public static boolean ifPrime(int number) {
		for (int i = 2; i <= Math.sqrt(number); ++i) {
			if (number % i == 0) {
				return false;
			}
		}
		return true;
	}
}
