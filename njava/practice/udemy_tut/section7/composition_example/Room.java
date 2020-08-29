package com.compositionexample;

public class Room {
	private int plates;
	private int cups;
	private Wall wall1;
	private Wall wall2;
	private Wall wall3;
	private Wall wall4;
	private Ceiling ceiling;
	private Bed bed;
	private Lamp lamp;

	public Room(int plates, int cups, Wall wall1, Wall wall2, Wall wall3, Wall wall4, Ceiling ceiling, Bed bed, Lamp lamp) {
		this.plates = plates;
		this.cups = cups;
		this.wall1 = wall1;
		this.wall2 = wall2;
		this.wall3 = wall3;
		this.wall4 = wall4;
		this.ceiling = ceiling;
		this.bed = bed;
		this.lamp = lamp;
	}

	public Lamp getLamp() {
		return this.lamp;
	}

	public void makeBed() {
		System.out.println("Room -> Making Bed");
		bed.make();
	}
}
