package com.abstraction_demo;

interface Interfacedemo {
	final static String STATEMENT = "this is a constant";
	public void m1();
	public void m2();
	public default void m4() {
		System.out.println("this is default");
	}
}