package com.compositionexample;

public class Lamp {
	private String lightColor;
	private boolean battery;
	private int globRating;

	public Lamp(String lightColor, boolean battery, int globRating) {
		this.lightColor = lightColor;
		this.battery = battery;
		this.globRating = globRating;
	}

	public void turnOn() {
		System.out.println("Lamp turned on");
	}

	public String getLightColor() {
		return lightColor;
	}
	public boolean getBattery() {
		return battery;
	}
	public int getGlobRating() {
		return globRating;
	}
}
