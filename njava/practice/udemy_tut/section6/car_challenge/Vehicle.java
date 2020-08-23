package com.vehicle;

public class Vehicle {
	private String name;
	private int wheels;
	private double weight;
	private double mileage;
	private int hp;

	public Vehicle() {
		this("Vehicle", 4, 0, 0, 0);
	}

	public Vehicle(String name, int wheels, double weight, double mileage, int hp) {
		this.name = name;
		this.wheels = wheels;
		this.weight = weight;
		this.mileage = mileage;
		this.hp = hp;
	}

	public String getName() {
		return name;
	}
	public int getWheels() {
		return wheels;
	}
	public double getWeight() {
		return weight;
	}
	public double getMileage() {
		return mileage;
	}
	public int getHp() {
		return hp;
	}

	public void move() {
		System.out.println("Vehicle does move!");
	}
}
