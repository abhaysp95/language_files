/* finally block runs after try/catch block whether or not try block executed
 * successfully. */

/* An exception might cause an error that terminates the current method,
 * causing its premature return. However, that method may have opened a file
 * or a network connection that needs to be closed. Such type of
 * circumstances are common in programming */

package using_finally;

class UseFinally {
	public static void getException(int what) {
		int t;
		int[] nums = new int[2];

		try {
			switch(what) {
				case 0:
					t = 10 / 2;  // generate div-by-zero exceptions
					break;
				case 1:
					nums[4] = 4;
					break;
				case 2:
					return;
			}
		}
		catch (ArithmeticException ae) {
			System.out.println("Can't divide by zero");
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("Array finished");
		}
		finally {
			System.out.println("Finally statement, leaving try");
		}
	}
}

class UseFinally1 {
	public static void getException(int what) {
		int t;
		int[] nums = new int[2];

		try {
			try {
				switch(what) {
					case 0:
						t = 10 / 2;  // generate div-by-zero exceptions
						break;
					case 1:
						nums[4] = 4;
						break;
					case 2:
						return;
				}
			}
			catch (ArithmeticException ae) {
				System.out.println("Can't divide by zero");
			}
			finally {
				System.out.println("First Finally statement, leaving try");
			}
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("Array finished");
		}
		finally {
			System.out.println("Second Finally statement, leaving try");
		}
	}
}


class FinallyDemo {
	public static void main(String[] args) {
		for (int i = 0; i < 3; ++i) {
			UseFinally.getException(i);
			System.out.println();
		}

		System.out.println("---------------------------");

		for (int i = 0; i < 3; ++i) {
			UseFinally1.getException(i);
			System.out.println();
		}
	}
}
