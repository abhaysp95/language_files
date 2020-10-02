// Write and then read back binary data

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.FileInputStream;

class RWData {
	public static void main(String[] args) {
		int i = 10;
		double d = 1032.34;
		boolean b = true;

		/** Comment this to check for the ArrayIndexOutOfBoundsException */
		/*if (args.length != 1) {
			System.out.println("Usage: provide a file name to write");
			return;
		}*/
		/** To check for FileNotFoundException, you have to first read, because
		 * if you give a filename which isn't there and the first operation you
		 * performing is write and then reading from samefile, it will not be a
		 * exception */

		// write some values
		try (DataOutputStream dataOut = new DataOutputStream(new FileOutputStream(args[0]))) {
			System.out.println("Writing " + i);  // note that we don't need to conversion here(but again when did)
			dataOut.writeInt(i);

			System.out.println("Writing " + d);
			dataOut.writeDouble(d);

			System.out.println("Writing " + b);
			dataOut.writeBoolean(b);

			System.out.println("Writing " + 12.2 * 7.4);
			dataOut.writeDouble(12.2 * 7.4);
		}
		catch (ArrayIndexOutOfBoundsException ae) {
			System.out.println("File Name not provided");
			return;
		}
		catch (FileNotFoundException fe) {
			System.out.println("File not found to open");
		}
		catch (IOException e) {
			System.out.println("Write error");
			return;
		}

		/** you can see in the file now that input written is in binary format
		 * and not human-readable but now lets read those binaries */

		System.out.println();

		// Now, read them back
		try (DataInputStream dataIn = new DataInputStream(new FileInputStream(args[0]))) {
			i = dataIn.readInt();
			System.out.println("Reading " + i);

			d = dataIn.readDouble();
			System.out.println("Reading " + d);

			b = dataIn.readBoolean();
			System.out.println("Reading " + b);

			d = dataIn.readDouble();
			System.out.println("Reading " + d);

			/** trying to read more intentionally */
			/*i = dataIn.readInt();
			System.out.println("Reading " + i);*/
			// as thought this will give read error

			/** so write is done one at a time and so does read */
		}
		catch (FileNotFoundException fe) {
			System.out.println("File not found to open");
		}
		catch (IOException e) {
			System.out.println("Read error");
			return;
		}
	}
}
