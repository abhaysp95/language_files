/* read from file */

import java.io.FileInputStream;
import java.io.IOException;

class ShowFile {
	public static void main(String[] args) {
		int i;
		FileInputStream fin = null;

		if (args.length != 1) {
			System.out.println("Usage: show file name");
			return;
		}

		try {
			fin = new FileInputStream(args[0]);
			do {
				i = fin.read();
				if (i != -1) {
					System.out.println((char) i);
				}
			} while(i != -1);
		}
		catch (FileNotFoundException e) {
			System.out.println("File not found");
		}
		catch (IOException e) {
			System.out.println("An I/O error occured");
			// cause of read()
		}
		finally {
			try {
				if (fin != null) {
					fin.close();
				}
			}
			catch (IOException e) {
				System.out.println("Error in closing file");
			}
		}
	}
}
