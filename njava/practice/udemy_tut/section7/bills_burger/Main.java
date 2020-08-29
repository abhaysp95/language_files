package practice.udemy_tut.section7.bills_burger;

public class Main {
	public static void main(String[] args) {
		Burger burger = new Burger("Defualt", "default", 10);
		System.out.println("Base price: " + burger.getBasePrice());
		burger.addLettuce();
		burger.addSauce();
		System.out.println("Overall Price: " + burger.getOverallPrice());
		burger.showAdditionalItems();

		System.out.println("--------------------------");

		HealthyBurger healthyBurger = new HealthyBurger("healthy", 14);
		System.out.println("Base price of healthyBurger: " + healthyBurger.getBasePrice());
		healthyBurger.addCarrot();
		healthyBurger.addOnion();
		System.out.println(healthyBurger.getOverallPrice());
		healthyBurger.showAdditionalItems();

		System.out.println("--------------------------");

		DeluxeBurger deluxeBurger = new DeluxeBurger("deluxe", "deluxe", 25);
		System.out.println("Base Price of deluxeBurger: " + deluxeBurger.getBasePrice());
		deluxeBurger.showAdditionalItems();
		deluxeBurger.removeChips();
		System.out.println(deluxeBurger.getOverallPrice());
		deluxeBurger.showAdditionalItems();
	}
}
