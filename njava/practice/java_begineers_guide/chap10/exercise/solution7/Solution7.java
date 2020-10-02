/** Program that copies a text file and converts all spaces to hyphen(-), using
 * byte stream and traditional approach of closing */

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

class PerformOperation {
	String fname1;
	String fname2;

	PerformOperation(String fname1, String fname2) {
		this.fname1 = fname1;
		this.fname2 = fname2;
	}

	public void copyFile() throws FileNotFoundException, IOException {
		int i;
		FileInputStream fin = null;
		FileOutputStream fout = null;
		try {
			fin = new FileInputStream(this.fname1);
			fout = new FileOutputStream(this.fname2);

			do {
				i = fin.read();
				if (i != -1) {
					if (i == ' ') {
						fout.write('-');
					}
					else {
						fout.write(i);
					}
				}
			} while (i != -1);
		}
		/*catch (FileNotFoundException fie) {
			System.out.println("File not found to read from");
			// cause if write file is not found, new one will be created
			return;
		}
		catch (IOException ie) {
			System.out.println("I/O exception occured: " + ie);
			return;
		}*/
		finally {
			fin.close();
			fout.close();
		}
	}
}

public class Solution7 {
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
