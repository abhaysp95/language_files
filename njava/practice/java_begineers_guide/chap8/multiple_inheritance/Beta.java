package multiple_inheritance;

public interface Beta extends Alpha {
	//@Override
	default void WhatIsIt() {
		Alpha.super.WhatIsIt();
		System.out.println("This is Beta");
	}
	// remind you that unlike classes extending multiple classes, interface can
	// extend multiple interfaces and so can classes
}
