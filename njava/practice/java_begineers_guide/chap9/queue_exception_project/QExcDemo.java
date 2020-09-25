package queue_exception;

import queue_exception_interface.ICharQ;
import queue_exception.FixedQueue;

public class QExcDemo {
	public static void main(String[] args) {
		FixedQueue q = new FixedQueue(10);
		char ch;
		int i;

		try {
			// overrun the queue
			for (i = 0; i < 11; ++i) {
				System.out.print("Attempting to store: " + (char) ('A' + i));
				q.put((char) ('A' + i));  // Exception can come from here
				System.out.println(" - Ok");
			}
			System.out.println();
		}
		catch (QueueFullException qfe) {
			System.out.println(qfe);
		}
		System.out.println();

		try {
			// over-empty the queue
			for (i = 0; i < 11; ++i) {
				System.out.print("Getting next char: ");
				ch = q.get();  // Exception can come from here
				System.out.println(ch);
			}
		}
		catch (QueueEmptyException qee) {
			System.out.println(qee);
		}

		q.set0();  // reset geloc and putloc again

		System.out.println("Filling the queue again:");
		try {
			// overrun the queue
			for (i = 0; i < 11; ++i) {
				System.out.print("Attempting to store: " + (char) ('A' + i));
				q.put((char) ('A' + i));  // Exception can come from here
				System.out.println(" - Ok");
			}
			System.out.println();
		}
		catch (QueueFullException qfe) {
			System.out.println(qfe);
		}
		System.out.println();

		q.setQ(((ICharQ) q).reset(q.getQ().length));  // you also have to change getloc for this too,
		// changing from outside like this isn't a good idea
		try {
			// over-empty the queue
			for (i = 0; i < 11; ++i) {
				System.out.print("Getting next char: ");
				ch = q.get();  // Exception can come from here
				System.out.println(ch);
			}
		}
		catch (QueueEmptyException qee) {
			System.out.println(qee);
		}
	}
}
