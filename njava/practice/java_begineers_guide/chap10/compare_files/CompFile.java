// Compare two file written data

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

class CompFile {
	public static void main(String[] args) {
		int i = 0, j = 0;
		try (FileInputStream fin1 = new FileInputStream(args[0]);
				FileInputStream fin2 = new FileInputStream(args[1])) {
			do {
				i = fin1.read();
				j = fin2.read();
				if (i != j) {
					break;
				}
			} while(i != -1 && j != -1);
			if (i != j) {
				System.out.println("Files Differ");
			}
			else {
				System.out.println("Files are same");
			}
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("Usage: provide two file names two compare");
		}
		catch (FileNotFoundException fe) {
			System.out.println("File not found: " + fe);
		}
		catch (IOException ie) {
			System.out.println("Error in reading file: " + ie);
		}
	}
}
