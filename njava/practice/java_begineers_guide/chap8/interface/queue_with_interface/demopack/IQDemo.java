package demopack;

import java.util.LinkedList;
import java.util.Scanner;
import qpack.ICharQ;

// A fixed size queue
class FixedQueue implements ICharQ {
	private char[] q;
	private int putloc, getloc;

	public FixedQueue(int size) {
		putloc = getloc = 0;
		q = new char[size];
	}

	public char[] getQ() {
		return this.q;
	}

	// put character in queue
	public void put(char ch) {
		if (putloc == q.length) {
			System.out.println(" - Queue is full");
		}
		q[putloc++] = ch;
	}

	public char get() {
		if (putloc == getloc) {
			System.out.println(" - Queue is empty");
			return (char) 0;
		}
		return q[getloc++];
	}
}

// A circular Queue(fixed size)
class CircularFixedQueue implements ICharQ {
	private char[] q;
	private int putloc, getloc;

	public CircularFixedQueue(int size) {
		q = new char[size];
		putloc = getloc = 0;
	}

	public char[] getQ() {
		return this.q;
	}

	public void put(char ch) {
		if (putloc + 1 == getloc || ((putloc == q.length) && (getloc == 0))) {
			System.out.println(" - CircularFixedQueue is full");
		}
		q[putloc++] = ch;
	}

	public char get() {
		if (getloc == putloc) {
			System.out.println(" - CircularFixedQueue is empty");
			return (char) 0;
		}
		return q[getloc++];
	}

	public void hello() {
		System.out.println("Hello for default implementation method from CircularFixedQueue");
	}
}

// DynIncreaseQueue
class DynIncreaseQueue implements ICharQ {
	private char[] q;
	private int putloc, getloc;

	public DynIncreaseQueue(int size) {
		// size to initialize array
		q = new char[size];
		putloc = getloc = 0;
	}

	public char[] getQ() {
		return this.q;
	}

	public void put(char ch) {
		if (putloc == q.length) {
			// increase queue size
			char[] t = new char[q.length * 2];
			// copy elements
			for (int i = 0; i < q.length; ++i) {
				t[i] = q[i];
			}
			// give q the referecne back
			q = t;
		}
		q[putloc++] = ch;
	}

	public char get() {
		if (putloc == getloc) {
			System.out.println(" - DynIncreaseQueue is empty");
			return (char) 0;
		}
		return q[getloc++];
	}
}

// Dynamic Queue(linkedlist)
class DynQLinkedList implements ICharQ {
	private LinkedList<Character> q;
	private int putloc, getloc;

	DynQLinkedList() {
		q = new LinkedList<Character>();
		putloc = getloc = 0;
	}

	public LinkedList<Character> getQ() {
		return this.q;
	}

	public void put(char ch) {
		// linkedList will not get empty
		q.add(ch);
		putloc++;
	}

	public char get() {
		if (getloc == putloc) {
			System.out.println(" - Queue is empty");
			return (char) 0;
		}
		return q.get(getloc++);
	}
}

class IQDemo {
	static Scanner scan = new Scanner(System.in);
	static IQDemo content = new IQDemo();

	public static void main(String[] args) {
		ICharQ q1 = new FixedQueue(10);
		ICharQ q2 = new CircularFixedQueue(10);
		ICharQ q3 = new DynIncreaseQueue(10);
		ICharQ q4 = new DynQLinkedList();

		// This is just to show the use of default interface method
		q1.hello();
		q2.hello();
		System.out.println();
		//content.putContent(q1, 10);
		//content.showContent(q1, 10);

		//content.putContent(q2, 10);
		//content.showContent(q2, 10);
		// select queue first
		ICharQ selectedQ;
		boolean quit = false;
		while (!quit) {
			System.out.println("Select a queue: ");
			String choice = scan.nextLine();
			switch(choice) {
				case "q":
				case "Q":
					System.out.println("Exiting!");
					quit = true;
					break;
				case "q1":
					selectedQ = q1;
					content.opToPerform(selectedQ);
					break;
				case "q2":
					selectedQ = q2;
					content.opToPerform(selectedQ);
					break;
				case "q3":
					selectedQ = q3;
					content.opToPerform(selectedQ);
					break;
				case "q4":
					selectedQ = q4;
					content.opToPerform(selectedQ);
					break;
				default:
					System.out.println("Select the right right Queue");
			}
		}
	}

	private void opToPerform(ICharQ selectedQ) {
		boolean quit = false;
		while (!quit) {
			int choice = scan.nextInt();
			scan.nextLine();
			switch (choice) {
				case 0:
					System.out.println("Quiting!");
					quit = true;
					break;
				case 1:
					System.out.println("List filled");
					content.putContent(selectedQ, 10);
					break;
				case 2:
					System.out.println("Show the content of the Queue/Empty Queue");
					content.showContent(selectedQ, 10);
					break;
				case 3:
					String name = selectedQ.getClass().getName();
					if (name.equals("demopack.FixedQueue")) {
						selectedQ.reset(((FixedQueue) selectedQ).getQ());
					}
					else if (name.equals("demopack.CircularFixedQueue")) {
						selectedQ.reset(((CircularFixedQueue) selectedQ).getQ());
					}
					else if (name.equals("demopack.DynIncreaseQueue")) {
						selectedQ.reset(((DynIncreaseQueue) selectedQ).getQ());
					}
					else if (name.equals("demopack.DynQLinkedList")) {
						((DynQLinkedList) selectedQ).getQ();
					}
					System.out.println(name + " is now reset");
					break;
				default:
					System.out.println("Select right operation");
			}
		}
	}

	private void putContent(ICharQ ob, int size) {
		for (int i = 0; i < size; ++i) {
			ob.put((char) ('A' + i));
		}
	}

	private void showContent(ICharQ ob, int size) {
		System.out.print("Content of " + ob.getClass().getName());
		for (int i = 0; i < size; ++i) {
			System.out.println(ob.get());
		}
		System.out.println();
	}
}


/* this program can be changed very much to perform Queue operations through
 * overloading and overriding stuff, but this was just for demo purpose for
 * interface and using interface generic class */
