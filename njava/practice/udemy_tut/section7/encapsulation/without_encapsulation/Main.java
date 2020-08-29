package com.player;

public class Main {
	public static void main(String[] args) {
		Player player = new Player();
		player.name = "James";
		// see the problem here, name is changed to fullName is Player class and now it isn't accessible here
		player.health = 50;
		player.weapon = "Sword";

		int damage = 22;
		System.out.println("Current health: " + player.healthRemaining());
		player.loseHealth(damage);
		System.out.println("Current health: " + player.healthRemaining());
		damage = 34;
		player.loseHealth(damage);
		System.out.println("Current health: " + player.healthRemaining());
	}
}

/* you can see the problem here, the fields are accessed directly, so anyone can just do player.health and can change the health of the player which we certainly don't want, another thing is somethings could be changed in Player class and it'll affect here too */
