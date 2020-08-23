package com.wallarea;

public class Wall {
	private double width;
	private double height;

	public Wall() {
		this(0, 0);
	}

	public Wall(double width, double height) {
		if (width > 0) {
			this.width = width;
		}
		else {
			this.width = 0;
		}
		if (height > 0) {
			this.height = height;
		}
		else {
			this.height = 0;
		}
	}

	// getters
	public double getWidth() {
		return this.width;
	}
	public double getHeight() {
		return this.height;
	}

	// setters
	public void setWidth(double width) {
		if (width >= 0) {
			this.width = width;
		}
		else {
			this.width = 0;
		}
	}
	public void setHeight(double height) {
		if (height >= 0) {
			this.height = height;
		}
		else {
			this.height = 0;
		}
	}

	public double getArea() {
		return this.width * this.height;
	}
}
