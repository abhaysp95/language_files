class X {
	private int x;
	X (int x) {
		this.x = x;
	}

	int getX() { return this.x; }
}

class Y {
	private int y;
	Y (int y) {
		this.y = y;
	}

	int getY() { return this.y; }
}

class A {
	private int a;
	A (int a) { this.a = a; }

	int getA() { return this.a; }
}

class B extends A {
	private int b;
	B (int a, int b) {
		super(a);
		this.b = b;
	}

	int getB() { return this.b; }
}

class IncompatibleRef {
	public static void main(String[] args) {
		X x1 = new X(10);
		X x2 = new X(20);
		Y y = new Y(15);
		System.out.println("x1: " + x1.getX());
		System.out.println("x2: " + x2.getX());
		System.out.println("y: " + y.getY());
		x2 = x1;
		System.out.println("x2: " + x2.getX());
		// x2 = y;  // Incompatible Reference


		// But this can happen with superclass to subclass
		A a = new A(10);
		B b = new B(12, 15);
		a = b;  // ok, because b is derived from a
		//b = a;  // not ok,
		System.out.println("a: " + a.getA());
		System.out.println("b: " + b.getA());
		System.out.println("b: " + b.getB());
		// but
		// System.out.println("b: " + a.getB());  // wrong,
		// because, superclass doesn't know what subclass has defined
		// so, even when reference of subclass is given to superClass you'll
		// have access to those members of subclass only which are defined by
		// superclass
	}
}
