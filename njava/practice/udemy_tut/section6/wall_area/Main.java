package com.wallarea;

public class Main {
	public static void main(String ...args) {
		Wall wall = new Wall(5, 4);
		System.out.println("Wall Area: " + wall.getArea());

		wall.setHeight(-1.5);
		System.out.println("Wall width: " + wall.getWidth());
		System.out.println("Wall height: " + wall.getHeight());
		System.out.println("Wall Area: " + wall.getArea());

		Wall wall1 = new Wall(-1.25, -1.25);
		System.out.println("Wall Area: " + wall1.getArea());

		wall1.setHeight(-1.5);
		System.out.println("Wall width: " + wall1.getWidth());
		System.out.println("Wall height: " + wall1.getHeight());
		System.out.println("Wall Area: " + wall1.getArea());
	}
}
