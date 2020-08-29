package practice.udemy_tut.section7.encapsulation.with_encapsulation;

public class Player {
	private int health;
	private String name;
	private String weapon;

	public Player(int health, String name, String weapon) {
		this.name = name;
		if (health >= 0 && health <= 200) {
			this.health = health;
		}
		this.weapon = weapon;
	}

	public void loseHealth(int damage) {
		this.health -= damage;
		if (this.health <= 0) {
			System.out.println("Player knocked out");
		}
	}

	public int getHealth() {
		return this.health;
	}
}
