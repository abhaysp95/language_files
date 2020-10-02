/** Program that copies a text file and converts all spaces to hyphen(-), using character stream and using try-with-resources */

package exercise8_solution;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.FileNotFoundException;
import java.io.IOException;

class PerformOperation {
	String fname1;
	String fname2;

	PerformOperation(String fname1, String fname2) {
		this.fname1 = fname1;
		this.fname2 = fname2;
	}

	public void copyFile1() throws FileNotFoundException, IOException {
		int ch;
		try (FileReader fr = new FileReader(this.fname1);
				FileWriter fw = new FileWriter(this.fname2, true)) {
			while ((ch = fr.read()) != -1) {
				if (ch == ' ') {
					fw.write('-');
				}
				else {
					fw.write((char) ch);
				}
			}
		}
	}
}

public class Solution8 {
	public static void main(String[] args) {
		try {
			PerformOperation op = new PerformOperation(args[0], args[1]);
			op.copyFile();
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("Provide two files name to read and write from");
		}
		catch (FileNotFoundException fie) {
			System.out.println("File not found to read from");
			// cause if write file is not found, new one will be created
			return;
		}
		catch (IOException ie) {
			System.out.println("I/O exception occured: " + ie);
			return;
		}
	}
}
