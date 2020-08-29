package com.compositionexample;

public class Bed {
	private String style;
	private int quilts;
	private int pillows;
	private int height;

	public Bed(String style, int quilts, int pillows, int height) {
		this.style = style;
		this.quilts = quilts;
		this.pillows = pillows;
		this.height = height;
	}

	public String getStyle() {
		return style;
	}
	public int getQuilts() {
		return quilts;
	}
	public int getPillows() {
		return pillows;
	}
	public int getHeight() {
		return height;
	}

	public void make() {
		System.out.println("Bed -> Making");
	}
}
