package testing_demo;

import testing_interface.ITest;

class A {
	public void print() {
		System.out.println("This is class A");
	}
}

class B extends A implements ITest {
	public void print() {
		super.print();
		System.out.println("This is class B");
	}

	public void show(int n) {
		System.out.println("Number entered: " + n);
	}

	public void espaciallyB() {
		System.out.println("This is Class B speaking");
	}
}


public class Demo {
	public static void main(String[] args) {
		A ob1 = new B();   // generic type
		ITest ob2 = new B();  // generic type
		B ob3 = new B();
		ob1.print();

		/* ---- Uncomment line below to check error --- */
		//ob1.show();
		//show() is undefined in type A, cause it's an interface method which
		//class A has not implemented
		/* -------------------------------------- */



		/* ---- Uncomment line below to check error --- */
		//ob1.espaciallyB();
		//espaciallyB in not given in A but in B and ob1 is type of A
		/* -------------------------------------- */



		/* ---- Uncomment line below to check error --- */
		//ob2.print();
		//print() is not an interface method(neither of default interface method), so it can't be used
		/* -------------------------------------- */


		ob2.show(10);


		/* ---- Uncomment line below to check error --- */
		//ob2.espaciallyB();
		// same for espaciallyB() this is also not in interface ITest
		/* -------------------------------------- */




		ob3.print();
		ob3.show(20);
		ob3.espaciallyB();
	}
}
