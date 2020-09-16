package qpack;

import java.util.LinkedList;

public interface ICharQ {
	void put(char ch);
	char get();
	/* static interface are now supported and also now interface can include
	 * private methods */
	/* you can also variables here, which could work as constant */
	/* one interface can inherit other interface with 'extends', now the
	 * class implementing this new interface will have to have the method of
	 * both the interfaces */
	/* There's now default mode method for interface, which can be used to
	 * extend the functionality of interface without breaking the exisiting
	 * code as it will not be necessary to add that method to every class
	 * that implements this interface, previously we have to have a empty
	 * implementation of that method in the implementing class to not break
	 * code */
	/* But, this doesn't change the key aspect of interface: an interface
	 * still can't have instance variables. */
	/* Also, it's not possible to create an instance of an interface by itself */
	default void hello() {
		System.out.println("Default interface method");
	}
	default char[] reset(char[] q) {
		char[] newArray = new char[q.length];
		q = newArray;
		return q;
	}
	default LinkedList<Character> reset(LinkedList<Character> q) {
		// java's garbage collection should come in work, to destroy old ll
		q = new LinkedList<Character>();
		return q;
	}
	// as you can see, overloading is possible in interface with default methods
	// same stands for overriding too(not just default in overriding)
}
