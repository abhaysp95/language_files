/* Using multicatch */

/* Multi-catch allows two or more exceptions to be caught by the same catch
 * clause. Helpful in catching more than on exceptions with single clause to
 * handle the exceptions without code duplications */

package using_multicatch;

class MultiCatch {
	public static void main(String[] args) {
		int a = 88, b = 0;
		int result;
		char chs[] = {'A', 'B', 'C'};

		for (int i = 0; i < chs.length; ++i) {
			try {
				if (i == 0) {
					result = a / b;  // generate an ArithmeticException
				}
				else {
					chs[5] = 'X';  // Array Index out of bound
				}
			}
			catch (ArithmeticException | ArrayIndexOutOfBoundsException e) {
				System.out.println("Exception caught: " + e);
			}
		}
		System.out.println("After multicatch");


		System.out.println("----------------------------------------");

		try {
			UsingRethrows.testException();
		}
		catch (ArithmeticException | ArrayIndexOutOfBoundsException e) {
			System.out.println("Exception is: " + e);
		}
	}
}

class UsingRethrows {
	// statement for Rethrows(final rethrow)
	/* feature restricts the type of exceptions that can be rethrown to only
	 * those check exceptions that the associated 'try' block throws, that
	 * are not handled by preceding 'catch' clause(which also means to handle
	 * any exception thrown from 'catch' clause too, had it not been handled
	 * by preceding 'catch' clause, which I think in not possible(dunno)) */
	public static void testException()
			throws ArithmeticException, ArrayIndexOutOfBoundsException {
		int[] arr = {1, 2, 3, 0, 4, 7};
		int[] arr1 = {2, 0, 1};

		try {
			for (int i = 0; i < arr.length; ++i) {
				try {
					int res = arr[i] / arr1[i];
					System.out.println("Dividing: " + arr[i] + " / " +
							arr1[i] + " = " + res);
				}
				catch (ArithmeticException ae) {
					System.out.println("Can't divide by zero");
					throw ae;  // rethrowing again
				}
			}
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("Array finished");
			throw aie;  // rethrowing again
		}
	}
}
