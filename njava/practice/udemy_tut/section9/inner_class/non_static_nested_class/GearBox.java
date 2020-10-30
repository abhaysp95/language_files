import java.util.ArrayList;

public class GearBox {
	private ArrayList<Gear> gears;
	private int maxGears;
	private int currentGear = 0;
	private boolean clutchIn;

	public GearBox(int maxGears) {
		this.maxGears = maxGears;
		this.gears = new ArrayList<Gear>();
		Gear neutral = new Gear(0, 0.0);
		this.gears.add(neutral);

		for (int i = 0; i < maxGears; ++i) {
			addGear(i, i * 5.13);
		}
	}

	public void operateClutch(boolean in) {
		this.clutchIn = in;
	}

	public void addGear(int number, double ratio) {
		if (number > 0 && number < maxGears) {
			this.gears.add(new Gear(number, ratio));
		}
	}

	public void changeGear(int newGear) {
		if (newGear >= 0 && newGear < this.gears.size() && this.clutchIn) {
			this.currentGear = newGear;
			System.out.println("Gear " + newGear + " selected");
		}
		else {
			System.out.println("Grind");
			this.currentGear = 0;
		}
	}

	public double wheelSpeed(int revs) {
		if (clutchIn) {
			System.out.println("Scream!!");
			return 0.0;
		}
		return revs * gears.get(this.currentGear).getRatio();
	}

	/** instance of Gear should/could only be created by GearBox */

	private class Gear {
		private int currentGear;
		private double ratio;

		public Gear(int gearNum, double ratio) {
			this.currentGear = gearNum;
			this.ratio = ratio;
		}

		public double getRatio() {
			return ratio;
		}

		public double driveSpeed(int revs) {
			return revs * (this.ratio);
		}
	}

	/** Instance of Gear class have got all the acess to outer GearBox class(even private ones) */
}
