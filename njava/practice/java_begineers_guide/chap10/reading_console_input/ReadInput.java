/* Because, System.in is an instance of InputStream, you can automatically
 * have access to methods() defined by InputStream. This means you can use
 * read() method to read bytes from System.in */

/* Three versions of read():
   int read() throws IOException
   int read(byte[] data) throws IOException
   int read(byte[] data, int start, int max) throws IOException
*/

/* Notice that, any I/O excpetions that might be generated are thrown out of
 * main(), but you can also handle them yourselves */

import java.io.InputStream;
import java.io.IOException;
import java.io.PrintStream;

/* InputStream and PrintStream are accessible without import because they are
 * input/output stream derived from InputStream/OutputStream */

public class ReadInput {
	public static void main(String[] args)
			throws IOException {
		byte[] data = new byte[10];
		System.out.println("Enter some characters:");
		System.in.read(data);
		System.out.println("You entered:");
		for (int i = 0; i < data.length; ++i) {
			System.out.print((char) data[i]);
		}
		System.out.println();
		/*System.in.close();  // is it necessary ?
		System.out.close();  // same for this too*/

		System.out.println("Output in byte:");
		for (int i = 0; i < data.length; ++i) {
			System.out.write(data[i]);
		}
		System.out.println();
	}
}

/* Apart from print, println, write, Println also provides us with printf and
 * format giving detailed control */
