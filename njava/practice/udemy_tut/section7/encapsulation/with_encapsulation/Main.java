package practice.udemy_tut.section7.encapsulation.with_encapsulation;

public class Main {
	public static void main(String[] args) {
		Player player = new Player(250, "Joey", "Sword");
		System.out.println("Current health: " + player.getHealth());
		int damage = 35;
		player.loseHealth(damage);
		System.out.println("Current health: " + player.getHealth());
		damage = 53;
		player.loseHealth(damage);
		System.out.println("Current health: " + player.getHealth());
		damage = 72;
		player.loseHealth(damage);
		System.out.println("Current health: " + player.getHealth());
	}
}
