package com.abstraction_demo;

// interface will also generate class file
interface NewInterface {
	public void m3();
}

class AbsExtends extends Abstractdemo {
	@Override
	public void method1() {
		System.out.println("This is method1 from AbsExtends");
	}

	public void method3(int num) {
		System.out.println("This is the abstract method called from AbsExtends: " + num);
	}
}

class ImplementInterface implements Interfacedemo, NewInterface {

	// don't put @Override thing
	public void m1() {
		System.out.println("This is m1 from ImplementInterface " + STATEMENT);
	}

	public void m2() {
		System.out.println("This is m1 from ImplementInterface");
	}

	public void m3() {
		System.out.println("This is m1 from ImplementInterface");
	}
}


public class Main {
	public static void main(String ...args) {
		//Abstractdemo is abstract, can't be instatiated
		//Abstractdemo abd = new Abstractdemo();
		//abd.method1();
		AbsExtends absetd = new AbsExtends();
		absetd.method1();
		absetd.method3(10);
		ImplementInterface iit = new ImplementInterface();
		iit.m1();
		iit.m4();
	}
}