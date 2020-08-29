package com.compositionexample;

public class Main {
	public static void main(String ...args) {
		Wall wall1 = new Wall("North");
		Wall wall2 = new Wall("South");
		Wall wall3 = new Wall("East");
		Wall wall4 = new Wall("West");

		Ceiling ceiling = new Ceiling("Navy", 12);

		Bed bed = new Bed("Grand", 2, 4, 8);

		Lamp lamp = new Lamp("Blueish", false, 80);

		Room room = new Room(2, 4, wall1, wall2, wall3, wall4, ceiling, bed, lamp);

		room.getLamp().turnOn();  // call using getter getLamp()

		room.makeBed();  // not using getter, makeBed() in turn calls bed.make()
	}
}
