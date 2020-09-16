package multiple_inheritance;


/* Now, java still doesn't have concept for multiple inheritance but it has
 * this concept regarding to interface, a interface can extend multiple
 * interfaces and a class can also implement multiple interfaces */

public interface Alpha {
	void print2();
	default int getHardyRamanujan() {
		System.out.println("It's 1729");
		return 0;
	}
	default void WhatIsIt() {
		System.out.println("This is Alpha");
	}
	default void WhatIsMyNumber() {
		System.out.println("I'm number 1 according to time I was created");
	}
}
