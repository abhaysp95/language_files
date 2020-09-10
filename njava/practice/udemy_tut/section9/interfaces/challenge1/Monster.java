package practice.udemy_tut.section9.interfaces.challenge1;

import java.util.List;
import java.util.ArrayList;

public class Monster implements ISavable {
	private String name;
	private int score;
	private int strength;

	public Monster(String name, int score, int strength) {
		this.name = name;
		this.score = score;
		this.strength = strength;
	}

	// getters and setters
	public String getName() {
		return this.name;
	}
	public int getScore() {
		return this.score;
	}
	public int getStrength() {
		return this.strength;
	}

	public void setName(String name) {
		this.name = name;
	}
	public void setScore(int score) {
		this.score = score;
	}
	public void setStrength(int strength) {
		this.strength = strength;
	}

	@Override
	public String toString() {
		return "Monster{" +
			"name: " + name + ", " +
			"score: " + score + ", " +
			"strength: " + strength + ", " + "}";
	}

	@Override
	public List<String> write() {
		List<String> values = new ArrayList<String>();
		values.add(0, this.name);
		values.add(1, "" + this.score);
		values.add(2, "" + this.strength);
		return values;
	}
	@Override
	public void read(List<String> values) {
		if (values != null && values.size() > 0) {
			this.name = values.get(0);
			this.score = Integer.parseInt(values.get(1));
			this.strength = Integer.parseInt(values.get(2));
		}
	}
}
