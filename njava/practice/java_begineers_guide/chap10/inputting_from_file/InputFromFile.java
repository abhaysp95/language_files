/* To create a byte stream(there's character-based object file stream too) linked to a file, use FileInputStream or FileOutputStream.

   FileInputStream(String fileName) throws FileNotFoundException

   FileNotFoundException is subclass of IOException

   read() reads a single byte from the file(same as reading from console). It returns -1 when the end of file is encountered */



/* Display a text file. */

import java.io.IOException;  // it will also handle FileNotFoundException
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

class FromArgs {
	int i;
	FileInputStream fin;
	String fileName;

	public FromArgs() {
		this("File Not Found");
	}

	public FromArgs(String fileName) {
		this.fileName = fileName;
	}

	String openFile() {
		if (this.fileName.equals("File Not Found")) {
			return "File Not Found or File Name not given properly";
			// or just return silently
		}
		try {
			fin = new FileInputStream(this.fileName);
			return "";
		}
		catch (FileNotFoundException fnf) {
			System.out.println("File not found");
			return "false";
		}
	}

	void readFile() {
		try {
			do {
				/* since, i is of type int and read() is of byte stream, how is
				 * this printing every char correctly, like is it because of
				 * implicit conversion from byte to int or something ? */
				this.i = this.fin.read();
				if (i != -1) {
					System.out.write(i);
				}
			} while(i != -1);  // till end of file
		}
		catch (IOException | NullPointerException err) {
			System.out.println("Error reading file");
			return;
		}
	}

	boolean closeFile() {
		try {
			this.fin.close();  // this is important
			return true;
		}
		catch (IOException | NullPointerException err) {
			System.out.println("Error closing file");
			return false;
		}
	}
}

// Above class just for trial

abstract class InputFile {
	int i;
	FileInputStream fin;
	String fileName;

	public InputFile() {
		this("File Name not provided");
	}

	public InputFile(String fileName) {
		this.fileName = fileName;
	}

	public String getFileName() {
		return this.fileName;
	}

	public void setFileName(String fileName) {
		this.fileName = fileName;
	}

	abstract public boolean openFile();
	abstract public void readFile();
	abstract public boolean closeFile();
	// another way can be to use finally block to closeFile, since it's
	// necessary
}



class InputTakenFromArg extends InputFile {

	InputTakenFromArg(String fileName) {
		super(fileName);
	}

	public boolean openFile() {
		try {
			this.fin = new FileInputStream(this.fileName);
			return true;
		}
		catch (FileNotFoundException ffe) {
			System.out.println("File not found to open");
			return false;
		}
	}

	public void readFile() {
		System.out.println("Reading file content:\n");
		try {
			do {
				this.i = this.fin.read();
				if (this.i != -1) {
					System.out.write(this.i);
				}
			} while(this.i != -1);
		}
		catch (IOException ie) {
			System.out.println("Problem in reading file");
		}
	}

	public boolean closeFile() {
		try {
			this.fin.close();
			return true;
		}
		catch (IOException ie) {
			System.out.println("Problem in closing file");
			return false;
		}
	}
}


class InputTakenUp10Char extends InputFile {
	/* Just to take input from read() */

	private byte[] fileName;
	private String fName;

	InputTakenUp10Char() {
		this.fileName = new byte[10];
		this.fName = "";
	}

	private void changeToString() {
		for (int i = 0; i < this.fileName.length; ++i) {
			this.fName += ((char) fileName[i]);
		}
	}

	public void settingsForFile() {
		try {
			System.out.println("Enter file Name:");
			System.in.read(this.fileName, 0, 10);
			changeToString();  // make fileName as string from byte[] array
		}
		catch (IOException ioe) {
			//throw new IOException("Can't take input for FileName");
			System.out.println("Can't take input for FileName");
		}
	}

	@Override
	public String getFileName() {
		return this.fName;
	}

	public boolean openFile() {
		try {
			this.fin = new FileInputStream(this.fName);
			return true;
		}
		catch (FileNotFoundException ffe) {
			System.out.println("Can't open file");
			return false;
		}
	}

	public void readFile() {
		try {
			do {
				this.i = this.fin.read();
				System.out.write(this.i);
			} while (this.i != -1);
		}
		catch (IOException ioe) {
			System.out.println("Can't read file");
		}
	}

	public boolean closeFile() {
		try {
			this.fin.close();
			return true;
		}
		catch (IOException ioe) {
			System.out.println("Can't close file");
			return false;
		}
	}
}

public class InputFromFile {
	public static void main(String[] args) {
		String openingStatus;
		boolean closeStatus;
		try {
			FromArgs ob = new FromArgs(args[0]);
			openingStatus = ob.openFile();
			if (!openingStatus.isEmpty()) {
				return;
			}
			ob.readFile();
			closeStatus = ob.closeFile();
			if (closeStatus) {
				System.out.println("File closed successfully");
			}
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			FromArgs ob = new FromArgs();
			openingStatus = ob.openFile();
			if (openingStatus != null) {
				System.out.println(openingStatus);
				return;
			}
		}
		/* Note: above use of if-else is kindof unnecessary as try-catch blocks
		 * are already in use, this is just for illustration purpose */

		System.out.println("\n----------------------------");
		System.out.println("Trying now from child of abstract class InputFile");
		System.out.println("----------------------------\n");

		try {
			InputFile ob1 = new InputTakenFromArg(args[0]);
			System.out.println("Opening file: " + ob1.getFileName());
			if (!ob1.openFile()) {
				return;
			}
			ob1.readFile();
			if (ob1.closeFile()) {
				System.out.println("File closed successfully");
			}
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("No file name provided");
		}

		/*byte[] fName = new byte[10];
		System.out.println("Enter name:");
		try {
			System.in.read(fName, 0, 10);
			[>String fiName = "";
			for (int i = 0; i < fName.length; ++i) {
				fiName += ((char) fName[i]);
			}<]
			String fiName = fName.toString();
			System.out.println("New String: " + fiName);
		}
		catch (IOException ie) {
			System.out.println("input not taken");
		}*/

		System.out.println("\n----------------------------\n");

		try {
			InputFile ob2 = new InputTakenUp10Char();
			((InputTakenUp10Char) ob2).settingsForFile();
			ob2.setFileName(ob2.getFileName());
			System.out.println("Opening file: " + ob2.getFileName());

			// Now from here file isn't opening(check the problem)
			if (!ob2.openFile()) {
				return;
			}
			ob2.readFile();
			if (ob2.closeFile()) {
				System.out.println("File closed successfully");
			}
		}
		/*catch (IOException ioe) {
			System.out.println(ioe);
		}*/
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("No file name provided");
		}
	}
}
