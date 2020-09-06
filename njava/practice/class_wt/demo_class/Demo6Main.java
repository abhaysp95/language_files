class Demo6 {
	void f1() {
		System.out.println("f1(not static) called");
	}

	static void statfun() {
		System.out.println("statfun(static) called");
	}
}

class Demo6Main {
	public static void main(String args[]) {
		System.out.println("Main called");
		// now since class is also different, so we have to create object for f1
		// also we have to create object for static method too, since there's no memory for Demo6
		// Demo6.statfun();  error: <identifier> expected Demo6.statfun();
		Demo6 obj1 = new Demo6();
		obj1.f1();
		Demo6.statfun();
		obj1.statfun();  // memory is already created and this static function 'statfun()' is also getting memory
	}
}
