/** RandomAccessFile is not derived from InputStream or OutputStream, instead
 * it implements the interfaces DataInput and DataOutput. Due to this, methods
 * to read() and write() the primitive dataTypes such as readInt() and
 * writeDouble() are available and read() and write() are also supported */

// Demonstrate random access files

import java.io.RandomAccessFile;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Collections;
import java.util.List;
import java.util.ArrayList;
//import java.util.Random;

class Range {
	public List<Integer> range(int min, int max) {
		List<Integer> arr = new ArrayList<Integer>();
		for (int i = min; i < max; ++i) {
			arr.add(i);
		}
		return arr;
	}
}

class RandomAccessDemo {
	public static void main(String[] args) {
		double d;
		int count = 0;

		try (RandomAccessFile raf = new RandomAccessFile("args[0]", "rw")) {
			// write values to file}
			System.out.println("Putting data");
			for (double i = 10.00; i < 30.00; i += 1.54) {
				count++;
				System.out.println("Putting: " + i);
				raf.writeDouble(i);
			}

			System.out.println("Total count is: " + count);

			System.out.println("-----------------------------");
			// Now, read back specific values
			/*raf.seek(0);  // seek to the first double
			d = raf.readDouble();
			System.out.println("Got value: " + d);*/

			System.out.println("Reading Value: ");
			/** Using random number between given range that will not duplicate */
			Range rg = new Range();
			List<Integer> rangeList = rg.range(0, count);
			Collections.shuffle(rangeList);
			System.out.print("\nRangelist after first shuffle: { ");
			for (int val: rangeList) {
				System.out.print(val + ", ");
			}
			System.out.print("}\n");
			for (int i = 0; i < count; ++i) {
				int value = rangeList.get(i);
				raf.seek(8 * value);  // seek to next double
				d = raf.readDouble();
				System.out.println(value + " value: " + d);
			}

			System.out.println("\n-----------------------------");

			System.out.println();
			System.out.println("Reading every other random value");
			// shuffling again(just for fun)
			Collections.shuffle(rangeList);
			System.out.print("\nRangelist after first shuffle: { ");
			for (int val: rangeList) {
				System.out.print(val + ", ");
			}
			System.out.print("}\n");
			for (int i = 0; i < count; i += 2) {
				int value = rangeList.get(i);
				// the new-position given to seek is of Long
				raf.seek(8 * value);
				d = raf.readDouble();
				System.out.println(value + " value: " + d);
			}
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("Provide the filename to read and write");
			return;
		}
		catch (FileNotFoundException fi) {
			/** this is most likely not to occur as if file is not found, new
			 * file will be created */
			System.out.println("File Not Found: " + fi);
		}
		catch (IOException ie) {
			System.out.println("Trouble in reading or writing: " + ie);
		}
		/** can't remember what exception does Collections.shuffle gives */
	}
}
