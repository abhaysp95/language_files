class Demo7 {
	int a;
	static int s;

	// constructor
	Demo7() {
		System.out.println("Constructor Called");
	}

	void f1() {
		System.out.println("non static f1");
	}

	static void f2() {
		System.out.println("static f2");
	}
}

class Demo7Main {
	public static void main(String ...args) {
		Demo7.s = 7;  // static members are accessible through class names
		System.out.println("Current s: " + Demo7.s);
		Demo7.s = 10;
		System.out.println("Current s: " + Demo7.s);

		Demo7 demo = new Demo7();
		demo.a = 5;  // non-static requires object
		System.out.println("Current a: " + demo.a);

		// the above concept applies for both variables and functions

		Demo7.f2();
		demo.f1();
		demo.f2();  // will also work as obvious
	}
}
