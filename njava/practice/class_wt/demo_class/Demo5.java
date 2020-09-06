class Demo5 {
	void f1() {
		System.out.println("f1 called");
		f2();  // so, a non-static method can call static method without any object creation
		f3();  // so, a non-static method can call another non-static method without object creation(but how memory is given to non-static method)
		// statfun();  // this is now recursive
	}

	static void statfun() {
		// f1();  // it can't called directly because f1 is non-static method
		// error: f1();  // it can't called directly because f1 is non-static method

		// so we have to make object of f1
		Demo5 ob1 = new Demo5();
		ob1.f1();
		ob1.f3();
		System.out.println("statfun called");
		Demo5 ob2 = new Demo5();
		ob2.f1();  // now, f1 and f2 will get new memory also, but static method will not get new memory(they already got it)
		// obj2.f2();  // f2 can't be called cause this time(second object creation) error: can't find symbol
		ob2.f3();
		ob2 = ob1;
		ob2.f2();
		// on creating objects only non-static members take new memory
	}

	public static void main(String args[]) {
		statfun();  // so to be called from static method another method should be static, or else object should be created(in same class or public should be used)
	}

	static void f2() {
		System.out.println("f2 called");
	}

	void f3() {
		System.out.println("f3 called");
	}
}
