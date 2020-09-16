package multiple_inheritance;

public interface Delta {
	int COUNT = 10;

	default void WhatIsMyNumber() {
		System.out.println("I'm number 4 according to time I was created");
	}

	static int callStatic() {
		int start = 20;
		System.out.println("I'm static method in Delta");
		System.out.println("I'm using a final variable COUNT: " + COUNT);
		return start++;
	}
}
