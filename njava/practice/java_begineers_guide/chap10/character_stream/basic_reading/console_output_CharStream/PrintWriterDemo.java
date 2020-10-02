/** PrintWriter is one of the character-based classes. PrintWriter supports the
 * print() and println() methods for all types including Object. If an argument
 * is not primitive, the PrintWriter methods will call the object's toString()
 * method to print the result */

import java.io.PrintWriter;

public class PrintWriterDemo {
	public static void main(String[] args) {
		PrintWriter pw = new PrintWriter(System.out, true);
		// true is telling the Java to flush output stream every time a
		// println() method among other is called
		int i = 10;
		double d = 123.65;
		pw.println("Using a PrintWriter");
		pw.println(i);
		pw.println(d);

		pw.println(i +  " + " + d + " is " + (i + d));
	}
}

/** You can still use System.out to write text output to the console when
 * debugging or learning, but with PrintWriter will make your real-world
 * applications easier to internationalize */
