package multiple_inheritance;

public interface Beta extends Alpha {
	//@Override
	default void WhatIsIt() {
		Alpha.super.WhatIsIt();
		System.out.println("This is Beta");
	}
}
