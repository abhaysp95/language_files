package com.vehicle;

public class Hummer extends Car {
	private int roadServiceDurationLeft;
	public Hummer() {
		this(12);
	}
	public Hummer(int roadServiceDurationLeft) {
		super("Hummer", 1, 0, 0, 0, 1, 4, 4, 6);
		this.roadServiceDurationLeft = roadServiceDurationLeft;
	}
}
