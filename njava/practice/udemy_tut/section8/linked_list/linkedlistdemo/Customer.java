package practice.udemy_tut.section8.linked_list;

public class Customer {
	private String name;
	private double balance;

	public Customer(String name, double balance) {
		this.name = name;
		this.balance = balance;
	}

	public void setName(String name) {
		this.name = name;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}

	public String getName() {
		return this.name;
	}
	public double getBalance() {
		return this.balance;
	}
}
