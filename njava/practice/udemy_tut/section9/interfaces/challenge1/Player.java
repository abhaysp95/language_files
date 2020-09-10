// implementing ISavable

package practice.udemy_tut.section9.interfaces.challenge1;

import java.util.List;
import java.util.ArrayList;

public class Player implements ISavable {
	private String name;
	private int score;
	private int strength;
	private String weapon;

	public Player(String name, int score, int strength) {
		this.name = name;
		this.score = score;
		this.strength = strength;
		this.weapon = "Mjolnir";
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
	public String getWeapon() {
		return this.weapon;
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
	public void setWeapon(String weapon) {
		this.weapon = weapon;
	}

	@Override
	public String toString() {
		return "Player{" +
			"name: " + name + ", " +
			"score: " + score + ", " +
			"strength: " + strength + ", " +
			"weapon: " + weapon + "}";
	}

	@Override
	public List<String> write() {
		List<String> values = new ArrayList<String>();
		values.add(0, this.name);
		values.add(1, "" + this.score);
		values.add(2, "" + this.strength);
		values.add(3, this.weapon);
		return values;
	}
	@Override
	public void read(List<String> savedValues) {
		if (savedValues != null && !savedValues.isEmpty()) {
			this.name = savedValues.get(0);
			this.score = Integer.parseInt(savedValues.get(1));
			this.strength = Integer.parseInt(savedValues.get(2));
			this.weapon = savedValues.get(3);
		}
	}
}
