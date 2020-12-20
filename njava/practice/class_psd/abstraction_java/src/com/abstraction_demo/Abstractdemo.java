package com.abstraction_demo;

abstract class Abstractdemo {
	public void method1() {
		System.out.println("This is method1 from Abstractdemo");
	}

	// this method is not necessarily should be used(overriden) by the child class
	// cause the method itself is not abstract
	public void method2() {
		System.out.println("This is method1 from Abstractdemo");
	}

	// abstract method can't have body
	// this abstract method need to be overridden by the child class
	abstract public void method3(int num);
}