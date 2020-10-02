/** Character stream is the best option if you want to stroe Unicode text, In
 * general to perform character base I/O, you'll use FileReader and FileWriter.
 * FileWriter creates a writer that you can use to write a file. FileWriter is derived from OutputStreamWriter and Writer */

import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class KtoD {
	public static void main(String[] args) {
		String str;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter text: ('stop' to quit):");
		try (FileWriter fw = new FileWriter(args[0], true)) {
			// this true is telling if file already exists, append
			do {
				System.out.println(": ");
				str = br.readLine();
				if (str.compareTo("stop") == 0) {
					break;
				}
				str = str + "\r\n";  // add newline
				fw.write(str);
			} while(! str.equals("stop"));
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("Provide the filename");
			return;
		}
		catch (IOException ie) {
			System.out.println("I/O error: " + ie);
			return;
		}

		System.out.println("---------------------------");

		/** note: for reading through character stream, there's FileReader
		 * which is can be made similar to FileWriter */
		try (BufferedReader br1 = new BufferedReader(new FileReader(args[0]))) {
			while ((str = br1.readLine()) != null) {
				System.out.println(str);
			}
		}
		/** Since ArrayIndexOutOfBoundsException is already handled above for
		 * same reason, there's no point of catching it here */
		catch (IOException aie) {
			System.out.println("I/O Error: " + aie);
		}
		/** In the above case, FileReader is wrapped with BufferedReader, this
		 * gives it access to readLine() */
	}
}

