/** Usage of try-with-resources */

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

class ShowFile {

	public static void method1(String fileName) {
		int i;

		// The try-with-resources can be used only with those resources that implement the "AutoCloseable" interface

		try (FileInputStream fin = new FileInputStream(fileName)) {
			// scope of the fin is local to the try block, and close() is
			// implicitly called Also resource declared in the try statement is
			// implicitly final
			do {
				i = fin.read();
				if (i != -1) {
					System.out.print((char) i);
				}
			} while (i != -1);
		}
		catch (IOException exc) {
			System.out.println("I/O Error: " + exc);
		}
	}

	public static void method2(String fileName) throws FileNotFoundException {
		int i;

		/** With JDK 9, it is also possible for the resource specification of
		 * the try to consist of a variable that has been declared and
		 * initialized earlier in the program. However, that variable must be
		 * effectively final */

		final FileInputStream fin = new FileInputStream(fileName);

		try (fin) {
			do {
				i = fin.read();
				if (i != -1) {
					System.out.print((char) i);
				}
			} while (i != -1);
		}
		catch (IOException exc) {
			System.out.println("I/O Error: " + exc);
		}
	}

	public static void method3(String fileName) {
		int i;


		// with jdk 10, you can use local variable type interface to specify
		// the type of resource declared in a try-with-resource statement
		try (var fin = new FileInputStream(fileName)) {
			do {
				i = fin.read();
				if (i != -1) {
					System.out.print((char) i);
				}
			} while (i != -1);
		}
		catch (IOException exc) {
			System.out.println("I/O Error: " + exc);
		}
	}

	/** We can have more than one resource managed with a single try block */

	/** this method will manage resources for both read and write */
	public static void method4(String inputFileName, String outputFileName) {
		int i;


		// with jdk 10, you can use local variable type interface to specify
		// the type of resource declared in a try-with-resource statement
		try (FileInputStream fin = new FileInputStream(inputFileName);
				FileOutputStream fout = new FileOutputStream(outputFileName)) {
			/** After this try block ends both fin and fout block will be closed */
			System.out.println("Writing to \"" + outputFileName + "\"");
			do {
				i = fin.read();
				if (i != -1) {
					fout.write(i);
				}
			} while (i != -1);
		}
		catch (IOException exc) {
			System.out.println("I/O Error: " + exc);
		}
	}

	/** Unlike normal try block where the orignal exception is lost when
	 * exception inside try block leads to another exception that occurs when
	 * the resource is closed in a finally clause, with a try-with-resources
	 * statement, the second exception is suppressed, it's now lost, it's added
	 * to the list of suppressed exceptions associated with first exception
	 * getSuppressed() */

	public static void main(String[] args) {

		if (args.length != 2) {
			System.out.println("Usage: Enter file name");
			return;
		}

		method1(args[0]);
		try {
			method2(args[0]);
		}
		catch (FileNotFoundException ff) {
			System.out.println("File not found: " + ff);
		}
		method3(args[0]);
		method4(args[0], args[1]);
	}
}
