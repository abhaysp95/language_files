package practice.udemy_tut.section9.inner_class;

import java.util.ArrayList;

public class GearBox {
	private ArrayList<Gear> gears;
	private int maxGear;
	private int gearNumber = 0;
	private boolean isClutchIn;
	// private int currentGear = 0;  // to avoid confusion with innerClass's gearNumber

	public GearBox(int maxGear) {
		this.gears = new ArrayList<Gear>();
		this.maxGear = maxGear;
		Gear nuetral = new Gear(0, 0.0);
		this.gears.add(nuetral);

		for (int i = 0; i <= maxGear; ++i) {
			addGear(i, i * 12.3);
		}
	}

	public ArrayList<Gear> getGear() {
		return this.gears;
	}

	public void operateClutch(boolean state) {
		this.isClutchIn = state;
	}

	public void addGear(int number, double ratio) {
		if (number > 0 && number <= this.maxGear) {
			gears.add(new Gear(number, ratio));
		}
	}

	public void changeGear(int newGear) {
		if (newGear >= 0 && newGear <= this.gears.size() && this.isClutchIn) {
			this.gearNumber = newGear;
			System.out.println("Gear changed: " + newGear);
		}
		else {
			System.out.println("Grind!");
		}
	}

	public double wheelSpeed(int revs) {
		if (isClutchIn) {
			System.out.println("Scream!!");
			return 0.0;
		}
		else {
			return this.gears.get(this.gearNumber).getRatio() * revs;
		}
	}

	// innerClass of GearBox, private(following encapsulation)
	private class Gear {
		// this gearNumber is shadowing GearBox.this.gearNumber
		private int gearNumber;  // this is GearBox.Gear.gearNumber
		private double ratio;

		public Gear(int gearNumber, double ratio) {
			this.gearNumber = gearNumber;
			this.ratio = ratio;
		}

		public int getGearNumber() {
			return this.gearNumber;
		}

		public double getRatio() {
			return this.ratio;
		}

		public double driveSpeed(int rev) {
			return rev * this.ratio;
		}
	}
}

/* innerClass has access to all the fields and methods of its outer class */
