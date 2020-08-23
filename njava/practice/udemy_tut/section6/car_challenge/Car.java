package com.vehicle;

public class Car extends Vehicle {
	private int storage;
	private int doors;
	private int windows;
	private int maxGear;
	private int currentGear = 0;
	// .....

	public Car() {
		this(1, 4, 4, 5);
	}
	public Car(int storage, int doors, int windows, int maxGear) {
		super("Car", 4, 0, 0, 0);
		this.storage = storage;
		this.doors = doors;
		this.windows = windows;
		this.maxGear = maxGear;
		this.currentGear = 1;
	}
	public Car(String name, int wheels, double weight, double mileage, int hp, int storage, int doors, int windows, int maxGear) {
		super(name, wheels, weight, mileage, hp);
		this.storage = storage;
		this.doors = doors;
		this.windows = windows;
		this.maxGear = maxGear;
		this.currentGear = 1;
	}

	public String getStorage() {
		if (storage == 1) {
			return "There's storage in car";
		}
		else {
			return "There's no storage in car";
		}
	}
	public int getWindows() {
		return windows;
	}
	public int getDoors() {
		return doors;
	}
	public int getMaxGears() {
		return maxGear;
	}
	public int getCurrentGear() {
		return currentGear;
	}

	public void gearUp() {
		if (currentGear < maxGear) {
			currentGear++;
			// System.out.println("Gear changed to " + currentGear);
		}
		//else {
			//System.out.println("Max Gear!");
		//}
	}
	public void gearDown() {
		if (currentGear > 0) {
			currentGear--;
			//System.out.println("Gear changed to " + currentGear);
		}
		//else {
			//System.out.println("Min Gear!");
		//}
	}
}
