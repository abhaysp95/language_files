package throwing_exception;

import java.util.Arrays;
import java.lang.StringBuilder;

class Main {
	public static void main(String[] args) {
		ThrowDemo ob1 = new ThrowDemo();
		ob1.throwingException();

		System.out.println("---------------------------");

		ReThrowDemo ob2 = new ReThrowDemo();
		try {
			ob2.reThrowingException();
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("Fatal error: - Progam Terminated");
			// but actually not, since this is a catch block
		}

		System.out.println("---------------------------");

		ReThrowDemo1 ob3 = new ReThrowDemo1();
		try {
			ob3.reThrowingException();
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("Another Fatal error: - Progam Terminated");
			// but actually not, since this is a catch block
		}

		System.out.println("---------------------------");

		Testing ob4 = new Testing();
		ob4.arrayToString();
	}
}

// Throwing an exception
class ThrowDemo {
	void throwingException() {
		try {
			System.out.println("Before throw");
			//throw new ArithmeticException();
			throw new ArithmeticException("This is arithmetic exception");
			// you can only have one throw of a same object type
			/* Also, exception thrown must be an object of an exception class
			 * derived from Throwable. */
		}
		catch (ArithmeticException ae) {
			System.out.println("Exception caught: " + ae.getMessage());
			System.out.println("Exception caught: " + ae.getLocalizedMessage());
		}
		System.out.println("After try/catch block");
	}
}


// Rethrowing an exception
/* An exception caught by one catch can be rethrown to be caught by outer
 * catch. The most likely reason for rethrowing this way is to allow multiple
 * handlers access to the exception. Perhaps, one handler manages one aspect
 * of exception and other one copes with other aspect */
class ReThrowDemo {
	void reThrowingException() {
		int[] numer = {4, 8, 16, 32, 64, 128, 256};
		int[] denom = {2, 0, 4, 4, 0, 8};

		for (int i = 0; i < numer.length; ++i) {
			try {
				System.out.println(numer[i] + " / " +
						denom[i] + " = " + numer[i] / denom[i]);
			}
			catch (ArithmeticException ae) {
				System.out.println("Can't divide by Zero");
			}
			catch (ArrayIndexOutOfBoundsException aie) {
				System.out.println("Numer or Denom finished");
				throw aie;  // rethrowing an exception
			}
		}
	}
}

class ReThrowDemo1 {
	void reThrowingException() {
		int[] numer = {4, 8, 16, 32, 64, 128, 256};
		int[] denom = {2, 0, 4, 4, 0, 8};

		try {
			for (int i = 0; i < numer.length; ++i) {
				try {
					System.out.println(numer[i] + " / " +
							denom[i] + " = " + numer[i] / denom[i]);
				}
				catch (ArithmeticException ae) {
					// ae parametr recieves the given type exception object
					System.out.println("Can't divide by Zero");
				}
			}
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("Numer or Denom finished");
			throw aie;  // rethrowing an exception
		}
	}
}

class Testing {
	void arrayToString() {
		String sentence = "Hello! How are you?";
		String[] arr = sentence.split(" ");
		System.out.println(arr.toString());
		System.out.println(Arrays.toString(arr));  // returns string enclosed with [] like in array

		StringBuilder sb = new StringBuilder("This is from StringBuilder");
		char[] aCharArr = new char[] {'-', 'c', 'h', 'a', 'r'};
		String[] aStringArr = new String[] {"- first String, ", "Second String"};
		sb.append(aCharArr);
		sb.append(aStringArr[0]);  // appends string
		sb.append(aStringArr);  // it doesn't takes a String array but does takes string
		System.out.println(sb);
	}
}
