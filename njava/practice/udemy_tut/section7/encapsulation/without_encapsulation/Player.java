package com.player;

public class Player {
	public int health;
	public String fullName;
	public String weapon;

	public void loseHealth(int damage) {
		this.health -= damage;
		if (this.health <= 0) {
			System.out.println("Player knocked out");
		}
	}

	public int healthRemaining() {
		return this.health;
	}
}
