package com.vehicle;


// this was written as an example and there are things which can be put in individual cars class instead of general car class

public class Main {
	public static void main(String ...args) {
		Hummer hummer = new Hummer();
		System.out.println("Name: " + hummer.getName());
		System.out.println("Current Gear: " + hummer.getCurrentGear());
		hummer.gearUp();
		hummer.gearUp();
		System.out.println("Current Gear: " + hummer.getCurrentGear());
		hummer.gearDown();
		System.out.println("Current Gear: " + hummer.getCurrentGear());

		Hummer hummer1 = new Hummer(6);
		System.out.println("Name: " + hummer1.getName());
		System.out.println("Max Gear: " + hummer1.getMaxGears());
		System.out.println("Current Gear: " + hummer1.getCurrentGear());
		hummer1.gearUp();
		hummer1.gearUp();
		System.out.println("Current Gear: " + hummer1.getCurrentGear());
		hummer1.gearDown();
		System.out.println("Current Gear: " + hummer1.getCurrentGear());
	}
}
