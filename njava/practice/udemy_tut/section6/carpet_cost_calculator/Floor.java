package com.carpetcostcalculator;

public class Floor {
	private double length;
	private double width;

	public Floor(double width, double length) {
		if (width < 0) {
			this.width = 0;
		}
		else {
			this.width = width;
		}
		if (length < 0) {
			this.length = 0;
		}
		else {
			this.length = length;
		}
	}

	public double getArea() {
		return this.length * this.width;
	}
}
