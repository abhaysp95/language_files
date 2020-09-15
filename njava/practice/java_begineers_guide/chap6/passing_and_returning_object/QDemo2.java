// A queue class for characters

class Queue {
	private char[] q;
	private int putloc, getloc = 0;

	// construct an empty queue
	Queue(int size) {
		q = new char[size];
		putloc = getloc = 0;
	}

	Queue(char[] arr) {
		putloc = getloc = 0;
		q = new char[arr.length];
		for (int i = 0; i < arr.length; i++) {
			put(arr[i]);
		}
	}

	Queue(Queue ob) {
		getloc = ob.getloc;
		putloc = ob.putloc;
		q = new char[ob.q.length];

		for (int i = getloc; i < putloc; i++) {
			q[i] = ob.q[i];
		}
	}

	// put character in Queue
	void put(char ch) {
		if (putloc == q.length) {
			System.out.println(" - Queue is full");
			return;
		}
		q[putloc++] = ch;
	}

	// no need
	/*void put(int index, char ch) {
		if ((index >= getloc && index < putloc) && putloc != q.length) {
			q[index] = ch;
			putloc++;
		}
	}*/

	char get() {
		if (getloc == putloc) {
			System.out.println(" - Queue is empty");
			return (char) 0;
		}
		return q[getloc++];
	}
}

public class QDemo2 {
	public static void main(String[] args) {
		Queue q1 = new Queue(10);

		char[] name = {'T', 'o', 'm'};
		Queue q2 = new Queue(name);

		char ch = Character.MIN_VALUE;

		// put some characters in q1
		for (int i = 0; i < 10; i++) {
			q1.put((char) ('A' + i));
		}

		Queue q3 = new Queue(q1);

		System.out.println("Contents of q1: ");
		for (int i = 0; i < 10; ++i) {
			ch = q1.get();
			System.out.print(ch);
		}

		System.out.println("\n");

		System.out.println("Contents of q2: ");
		for (int i = 0; i < 10; ++i) {
			ch = q2.get();
			System.out.print(ch);
		}

		System.out.println("\n");

		System.out.println("Contents of q3: ");
		for (int i = 0; i < 10; ++i) {
			ch = q3.get();
			System.out.print(ch);
		}
		System.out.println();
	}
}
