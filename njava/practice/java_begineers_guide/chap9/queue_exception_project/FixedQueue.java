package queue_exception;

import queue_exception_interface.ICharQ;
import queue_exception.QueueEmptyException;
import queue_exception.QueueFullException;

class FixedQueue implements ICharQ {
	private char q[];
	private int putloc, getloc;

	public char[] getQ() {
		return this.q;
	}

	public void setQ(char[] q) {
		this.q = q;
	}

	public FixedQueue(int size) {
		q = new char[size];
		putloc = getloc = 0;
	}

	public void set0() {
		this.putloc = this.getloc = 0;
	}

	// put characters
	public void put(char ch) throws QueueFullException {
		if (this.putloc == q.length) {
			throw new QueueFullException(q.length);
		}
		q[putloc++] = ch;
	}

	// get characters out of Queue
	public char get() throws QueueEmptyException {
		if (this.getloc == putloc) {
			throw new QueueEmptyException();
		}
		return q[getloc++];
	}
}
