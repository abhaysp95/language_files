public class FindPrimeInGivenRange {
	public static void main(String args[]) {
		// find the three prime numbers in the given range
		int primeNumbersToFind = 5;
		int count = 0;
		for (int i = 10; i < 40; ++i) {
			if (isPrime(i)) {
				count++;
				System.out.println("Found Prime Number: " + i);
				if (count == primeNumbersToFind) {
				System.out.println("Exiting!");
					break;
				}
			}
		}
	}

	public static boolean isPrime(int number) {
		if (number == 1) {
			return false;
		}
		//for (int i = 2; i < number / 2; ++i) {
		for (int i = 2; i <= (long)Math.sqrt(number); ++i) {  // new logic
			if (number % i == 0) {
				return false;
			}
		}
		return true;
	}
}
