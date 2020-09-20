package handle_error_gracefully;

class ExcDemo3 {
	public static void main(String[] args) {
		/*int[] numer = {4, 8, 16, 32, 64, 128, 256};
		int[] denom = {2, 0, 4, 4, 0, 8};

		for (int i = 0; i < numer.length; ++i) {
			if (i < denom.length) {
				try {
					System.out.println(numer[i] + " / " +
							denom[i] + " = " + numer[i] / denom[i]);
				}
				catch (ArithmeticException e) {
					System.out.println("Can't divide by zero");
				}
				[> Once an exception has been handled, it is removed from the
				 * system. Therefore, each pass in the program through the
				 * loop enters the try block anew; <]
			}
			else {
				System.out.println("No denominator for " + numer[i]);
			}*/
			// or instead of else block we can use another catch, sec ExcDemo31
		//}


		ExcDemo31 ob1 = new ExcDemo31();
		ob1.showExc();

		System.out.println("--------------------");

		ExcDemo32 ob2 = new ExcDemo32();
		ob2.showExc();

		System.out.println("--------------------");

		ExcDemo33 ob3 = new ExcDemo33();
		ob3.showExc();
	}
}

class ExcDemo31 {
	void showExc() {
		int[] numer = {4, 8, 16, 32, 64, 128, 256};
		int[] denom = {2, 0, 4, 4, 0, 8};

		for (int i = 0; i < numer.length; ++i) {
			try {
				System.out.println(numer[i] + " / " +
						denom[i] + " = " + numer[i] / denom[i]);
			}
			catch (ArithmeticException ae) {
				System.out.println("Can't divide by zero");
			}
			catch (ArrayIndexOutOfBoundsException aie) {
				System.out.println("numer or denom finished");
			}
		}
	}
}

/* A catch clause for a superclass will also match any of its subclass. For
 * example, since the superclass of all exceptions in Throwable, to catch all
 * possible exceptions catch Throwable, if you want to catch exception of both
 * super and subclass type, put the subclass first in the catch sequences */
class ExcDemo32 {
	void showExc() {
		int[] numer = {4, 8, 16, 32, 64, 128, 256};
		int[] denom = {2, 0, 4, 4, 0, 8};

		for (int i = 0; i < numer.length; ++i) {
			try {
				System.out.println(numer[i] + " / " +
						denom[i] + " = " + numer[i] / denom[i]);
			}
			catch (ArrayIndexOutOfBoundsException aie) {
				System.out.println("numer or denom finished");
			}
			catch (Throwable t) {
				System.out.println("Some error occured");
			}
		}
	}
}

class ExcDemo33 {
	void showExc() {
		int[] numer = {4, 8, 16, 32, 64, 128, 256};
		int[] denom = {2, 0, 4, 4, 0, 8};

		try {
			for (int i = 0; i < numer.length; ++i) {
				try {
					System.out.println(numer[i] + " / " +
							denom[i] + " = " + numer[i] / denom[i]);
				}
				catch (ArithmeticException ae) {
					System.out.println("Can't divide by Zero");
				}
			}
		}
		/* An exception generated with inner try block and not caught by the
		 * catch associated with that try is propagated to the outer try
		 * block */
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("numer or denom finished(from outer catch block)");
		}
	}
}
/* The above block makes an important point that can be generalized. Often
 * nested try blocks are used to allow different categories of errors to be
 * handled in different ways. Some types of errors are catestrophic and
 * cannot be fixed. Some are minor and can be handled immediately. YOu might
 * use an outer try block to catch the most severe errors, allowing inner try
 * blocks to handle less serious one. */
