// Demonstrate dynamic method dispatch


class Sup {
	void who() {
		System.out.println("It's Sup!");
	}
}

class Sub1 extends Sup {
	void who() {
		System.out.println("It's Sub1");
	}
}

class Sub2 extends Sup {
	void who() {
		System.out.println("It's Sub2");
	}
}

class DynDispDemo {
	public static void main(String[] args) {
		Sup sup = new Sup();
		Sub1 sub1 = new Sub1();
		Sub2 sub2 = new Sub2();

		sup.who();
		sub1.who();
		sub2.who();

		Sup superef;
		superef = sup;
		superef.who();
		superef = sub1;
		superef.who();
		superef = sub2;
		superef.who();
		/* In each case the method 'who()' to call is determined by the type of
		 * object being reffered
		 * So, in other words, it is the type of object being reffered to(not
		 * type of the reference variable)
		 */
	}
}
