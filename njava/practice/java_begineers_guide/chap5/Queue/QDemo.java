// A queue class for character

//package practice.java_begineers_guide.chap5;

class Queue {
	char[] q;   // array holding queue
	int putloc, getloc;  // the put and get indice

	// constructor
	Queue(int size) {
		q = new char[size];
		putloc = getloc = 0;
	}

	// put a character in queue
	void put(char ch) {
		if (putloc == q.length) {
			System.out.println(" - Queue is full");
			return;
		}
		q[putloc++] = ch;
	}

	// get character from queue
	char get() {
		if (getloc == putloc) {
			System.out.println(" - Queue is empty");
			return (char) 0;
		}
		return q[getloc++];
	}
}

public class QDemo {
	public static void main(String[] args) {
		Queue bigQ = new Queue(100);
		Queue smallQ = new Queue(4);
		char ch = Character.MIN_VALUE;

		System.out.println("Using bigQ to store the alphabet.");
		// put numbers in bigQ
		for (int i = 0; i < 26; ++i) {
			bigQ.put((char) ('A' + i));
		}

		// retrieve elements from bigQ
		for (int i = 0; i < 26; ++i) {
			ch = bigQ.get();
			if (ch != (char) 0) {
				System.out.println(ch);
			}
		}
		System.out.println("\n");

		System.out.println("use smallQ to generate errors");
		for (int i = 0; i < 5; ++i) {
			System.out.println("Attemepting to store " + (char) ('z' - i));
			smallQ.put((char) ('z' - i));
			System.out.println();
		}
		System.out.println();

		// more errors on smallQ
		System.out.println("Contents of smallQ");
		for (int i = 0; i < 5; ++i) {
			ch = smallQ.get();
		}
		if (ch != (char) 0) {
			System.out.println(ch);
		}
	}
}
