class Demo9 {
	int a;

	Demo9() {
		this(2);  // if you are giving 0 here, then no need default constructor already makes the class variables(not static) 0
	}

	Demo9(int a) {
		this.a = a;
	}
}

class Demo9Main {
	public static void main(String ...args) {
		Demo9 demo = new Demo9();
		System.out.println("a: " + demo.a);

		Demo9 demo1 = new Demo9(5);
		System.out.println("a: " + demo1.a);
	}
}
