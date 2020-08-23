package com.point;

public class Point {
	private int x;
	private int y;

	// constructors
	public Point() {
		this(0, 0);
	}
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}

	// getters
	public int getX() {
		return this.x;
	}
	public int getY() {
		return this.y;
	}

	// setters
	public void setX(int x) {
		this.x = x;
	}
	public void setY(int y) {
		this.y = y;
	}

	// distance without any parameter should return distance between this point and point 0,0
	public double distance() {
		return Math.sqrt(this.x * this.x + this.y * this.y);
	}
	// difference between two points if point is given
	public double distance(int x, int y) {
		return Math.sqrt(Math.pow(this.x - x, 2) + Math.pow(this.y - y, 2));
	}
	// difference with parameter another of type point
	public double distance(Point point) {
		return Math.sqrt(Math.pow(this.x - point.x, 2) + Math.pow(this.y - point.y, 2));
	}
}
