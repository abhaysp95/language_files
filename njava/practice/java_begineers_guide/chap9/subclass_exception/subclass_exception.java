package subclass_exception;

/* just define a subclass of exception */

class NonIntResultException extends Exception {
	int n;
	int d;

	NonIntResultException(int n, int d) {
		this.n = n;
		this.d = d;
	}

	public String toString() {
		return "Result of " + n + " / " + d +
			" is non-integer.";
	}
}

class CustomExceptDemo {
	// here, numer contains some odd values

	public static void main(String[] args) {
		int[] numer = { 4, 8, 31, 72, 131, 613, 735, 1550 };
		int[] denom = { 2, 0, 4, 4, 0, 8 };

		try {
			for (int i = 0; i < numer.length; ++i) {
				try {
					if ((numer[i] % 2) != 0) {
						throw new NonIntResultException(numer[i], denom[i]);
					}
					System.out.println(numer[i] + " / " +
							denom[i] + " is " + numer[i] / denom[i]);
				}
				catch (ArithmeticException ae) {
					System.out.println("Can't divide by zero");
				}
				catch (NonIntResultException nie) {
					System.out.println(nie);
				}
			}
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("No matching element found, terminating");
		}
	}
}
