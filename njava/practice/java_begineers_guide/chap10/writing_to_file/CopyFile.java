import java.io.IOException;
import java.io.FileInputStream;
import java.io.FileOutputStream;

class CopyFile {
	public static void main(String[] args) {
		int i;
		FileInputStream fin = null;
		FileOutputStream fout = null;

		// making sure that both files are recieved
		if (args.length != 2) {
			System.out.println(("Usage: copy file --- from to ---"));
			return;
		}

		try {
			fin = new FileInputStream(args[0]);
			fout = new FileOutputStream(args[1]);

			do {
				i = fin.read();
				// read bytes from one file and write to another
				if (i != -1) {
					fout.write(i);
				}
			} while (i != -1);
		}
		catch (IOException ie) {
			System.out.println("I/O Exception: " + ie);
		}
		// free up the resource
		finally {
			try {
				if (fin != null) {
					fin.close();
				}
			}
			catch (IOException ie) {
				System.out.println("Error in closing input file");
			}
			try {
				if (fout != null) {
					fout.close();
				}
			}
			catch (IOException ie) {
				System.out.println("Error in closing input file");
			}
		}
	}
}
