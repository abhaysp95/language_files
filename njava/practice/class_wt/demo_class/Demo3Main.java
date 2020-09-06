class Demo3 {
	private int a = 0;
	void fun1(int x) {
		System.out.println(x);
	}
	void store(int x) {
		a = x;  // hmm, didn't used this keyword here
	}
	void display() {
		System.out.println(a);
	}
}

class Demo3Main {
	public static void main(String args[]) {
		Demo3 obj1 = new Demo3();  // demo3 is reference type variable
		obj1.fun1(5);
		obj1.fun1(8);
		Demo3 obj2 = new Demo3();  // can have more than one object for a class
		obj2.fun1(7);

		obj1.store(3);
		obj1.display();
		obj2.store(5);
		obj2.display();
		obj1.display();

		obj1 = obj2;  // now obj2 is having the reference of obj1
		obj1.display();
		obj2.store(21);
		obj1.display();
		obj1.store(23);
		obj2.display();
	}
}
