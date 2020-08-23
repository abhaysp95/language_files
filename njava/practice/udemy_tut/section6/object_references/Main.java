package com.objectreferences;

public class Main {
	public static void main(String ...args) {
		House house = new House("blue");
		House anotherHouse = house;  // pointing to the same object
		// in other words anotherHouse is referring to the same object to which house is referring
		System.out.println("house: " + house.getColor());
		System.out.println("anotherHouse: " + anotherHouse.getColor());

		anotherHouse.setColor("yellow");
		System.out.println("house: " + house.getColor());
		System.out.println("anotherHouse: " + anotherHouse.getColor());

		House greenHouse = new House("green");
		anotherHouse = greenHouse;
		// now anotherHouse is referring to object to which greenHouse is referring to
		System.out.println("house: " + house.getColor());
		System.out.println("greenHouse: " + greenHouse.getColor());
		System.out.println("anotherHouse: " + anotherHouse.getColor());
	}
}

/* keep in mind, java always have references to an object in memory, there's no way to access a object directly, everything is done through references */
