package practice.udemy_tut.section7.bills_burger;

public class Burger {
	private String breadType;
	private String meat;
	private boolean lettuce;
	private boolean tomato;
	private boolean carrot;
	private boolean sauce;
	private int price;
	private int overallPrice;

	public Burger(String breadType, String meat, int price) {
		this.breadType = breadType;
		this.meat = meat;
		this.price = price;
		this.overallPrice = getBasePrice();
	}

	public int getBasePrice() {
		return this.price;
	}

	public void addLettuce() {
		this.lettuce= true;
		System.out.println("Added Lettuce");
		this.overallPrice += 3;
	}

	public void addTomato() {
		this.tomato = true;
		System.out.println("Added Tomato");
		this.overallPrice += 2;
	}

	public void addCarrot() {
		this.carrot = true;
		System.out.println("Adding Carrot");
		this.overallPrice += 3;
	}

	public void addSauce() {
		this.sauce = true;
		System.out.println("Added Sauce");
		this.overallPrice += 5;
	}

	public String getOverallPrice() {
		return "Price of " + getClass().getSimpleName() + ": " + this.overallPrice;
	}
	// thought that "this.price" would call the price of class.price from
	// which class it is called, but no. So, I am overriding this method in
	// other class

	public void showAdditionalItems() {
		boolean flag = true;
		int count = 1;
		System.out.println("Additional items with burger: ");
		if (this.lettuce) {
			System.out.println(count++ + ": Lettuce");
			if (flag) {
				flag = false;
			}
		}
		if (this.tomato) {
			System.out.println(count++ + ": Tomato");
			if (flag) {
				flag = false;
			}
		}
		if (this.carrot) {
			System.out.println(count++ + ": Carrot");
			if (flag) {
				flag = false;
			}
		}
		if (this.sauce) {
			System.out.println(count++ + ": Sauce");
			if (flag) {
				flag = false;
			}
		}
		if (flag) {
			System.out.println("No additional items");
		}
	}
}

class HealthyBurger extends Burger {
	private boolean cucumber;
	private boolean onion;
	private int overallPrice;

	public HealthyBurger(String meat, int price) {
		super("rye bread roll", meat, price);
		this.overallPrice = getBasePrice();
	}

	@Override
	public int getBasePrice() {
		return super.getBasePrice();
	}

	public void addCucumber() {
		this.cucumber = true;
		System.out.println("Added Cucumber");
		this.overallPrice += 2;
	}

	public void addOnion() {
		this.onion = true;
		System.out.println("Adding Onion");
		this.overallPrice += 3;
	}

	@Override
	public String getOverallPrice() {
		return "Overall price of healthyBurger is: " + this.overallPrice;
	}

	@Override
	public void showAdditionalItems() {
		boolean flag = true;
		int count = 1;
		System.out.println("Additional items with burger: ");
		if (this.cucumber) {
			System.out.println(count++ + ": Cucumber");
			if (flag) {
				flag = false;
			}
		}
		if (this.onion) {
			System.out.println(count++ + ": Onion");
			if (flag) {
				flag = false;
			}
		}
		if (flag) {
			System.out.println("No additional items");
		}
	}
}

class DeluxeBurger extends Burger {
	private boolean chips;
	private boolean coke;
	private int overallPrice;

	public DeluxeBurger(String breadType, String meat, int price) {
		super(breadType, meat, price);
		this.chips = true;
		this.coke = true;
		this.overallPrice = getBasePrice();
	}

	@Override
	public int getBasePrice() {
		return super.getBasePrice();
	}

	public void removeChips() {
		System.out.println("Removed chips");
		this.overallPrice -= 4;
	}

	public void removeCoke() {
		System.out.println("Removed coke");
		this.overallPrice -= 7;
	}

	private void showRemovedItems() {
		boolean flag = true;
		int count = 1;
		System.out.println("Items removed: ");
		if (!this.chips) {
			System.out.println(count++ + ": Chips");
			if (flag) {
				flag = false;
			}
		}
		if (!this.coke) {
			System.out.println(count++ + ": Coke");
			if (flag) {
				flag = false;
			}
		}
		if (flag) {
			System.out.println("No item removed");
		}
	}

	@Override
	public String getOverallPrice() {
		return "Overall price of DeluxeBurger: " + this.overallPrice;
	}

	@Override
	public void showAdditionalItems() {
		System.out.println("All the items are included in package by default, but showing if any removed items");
		showRemovedItems();
	}
}
