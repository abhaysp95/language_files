package practice.udemy_tut.section8.bank_transactions;

import java.util.ArrayList;

public class Customer {
	private String name;
	private double balance; // initial transaction
	private ArrayList<Double> transactions;

	public Customer() {
		this("Not Provided", 0.0);
	}

	public Customer(String name) {
		this.name = name;
		this.balance = 0;
	}

	public Customer(String name, double balance) {
		this.name = name;
		this.balance = balance;
		transactions = new ArrayList<Double>();
		transactions.add(Double.valueOf(balance));  // or just use balance, it's still autoboxing
	}

	public String getName() {
		return this.name;
	}

	public double getBalance() {
		return this.balance;
	}

	public ArrayList<Double> getTransaction() {
		return this.transactions;
	}

	public void addCustomerTransaction(String method, double amount) {
		if (method == "debit") {
			makeDeposit(amount);
			transactions.add(Double.valueOf(amount));  // autoboxing
			System.out.println("Amount " + amount + " deposited");
		}
		else if (method == "credit") {
			doCredit(amount);
			transactions.add(Double.valueOf(amount));
			System.out.println("Amount " + amount + " credited");
		}
	}

	private void makeDeposit(double amount) {
		this.balance += amount;
	}

	private void doCredit(double amount) {
		if (this.balance >= amount) {
			this.balance -= amount;
		}
	}
}
