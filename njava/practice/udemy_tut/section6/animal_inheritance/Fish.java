package com.animalinheritance;

public class Fish extends Animal {
	private int eyes;
	private int gills;
	private int fins;

	public Fish(String name, double size, double weight, int eyes, int gills, int fins) {
		super(name, 1, 1, size, weight);
		this.eyes = eyes;
		this.gills = gills;
		this.fins = fins;
	}

	// behaviour - movement
	public void rest() {
		System.out.println("Fish rests");
	}
	private void moveMuscle() {
		System.out.println("Fish swims by moving muscles");
	}
	private void moveBackFins() {
		System.out.println("Fish gets support for swimming by moving back fins");
	}
	public void swim(double speed) {
		moveMuscle();
		moveBackFins();
		super.move(3.4);
	}
}
