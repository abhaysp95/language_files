package queue_exception_interface;

import queue_exception.QueueEmptyException;
import queue_exception.QueueFullException;

public interface ICharQ {
	// If method is throws exception, it should be mentioned in interface too
	void put(char ch) throws QueueFullException;
	char get() throws QueueEmptyException;

	//default char[] reset(ICharQ ob) {
		//return new char[ob.getQ().length];
	//}

	default char[] reset(int size) {
		return new char[size];
	}
}
