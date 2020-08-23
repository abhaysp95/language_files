package com.bankaccount;

public class Main {
	public static void main(String ...args) {
		// java automatically creates constructor for us(see below)
		BankAccount work = new BankAccount();
		work.setCustomerName("Tony");
		System.out.println("Name: " + work.getCustomerName());
		work.setBalance(7839.80);
		System.out.println("Current balance: " + work.getBalance());
		work.withdraw(430.29);
		System.out.println("Current balance after withdrawal: " + work.getBalance());
		work.deposit(234.77);
		System.out.println("Current balance after deposit: " + String.format("%.2f", work.getBalance()));
	}
}
