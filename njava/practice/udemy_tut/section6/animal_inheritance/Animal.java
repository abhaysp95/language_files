package com.animalinheritance;

public class Animal {
	private String name;
	private int brain;
	private int body;
	private double size;
	private double weight;

	public Animal(String name, int brain, int body, double size, double weight) {
		this.name = name;
		this.brain = brain;
		this.body = body;
		this.size = size;
		this.weight = weight;
	}

	// getters
	public String getName() {
		return this.name;
	}
	public int getBrain() {
		return this.brain;
	}
	public int getBody() {
		return this.body;
	}
	public double getSize() {
		return this.size;
	}
	public double getWeight() {
		return this.weight;
	}

	// behaviour
	public void eat() {
		System.out.println("Animal Eats");
	}

	public void move(double speed) {
		System.out.println("Animal moves at " + speed);
	}
}
