package com.bankaccount;

// if no package name is given it goes to default package
// public access modifier is needed to make the class/methods availabe to other packages
// not if the classes are different or classes are in different files
// but fields can be made public to use in other classes
class BankAccount {
	private long accountNumber = 0;
	private double balance = 0;
	private String customerName;
	private String email;
	private long phoneNumber = 0;

	// but if we explicitly create constructor than java says ok you're creating your own constructor, I won't try to overwrite it
	public BankAccount() {
		System.out.println("constructor for BankAccount class called");
	}

	// we can overloaded provided we change the number of parameters
	// see that in bank_account2

	// setters
	void setAccountNumber(long number) {
		this.accountNumber = number;  // keyword this, used to differentiate instance variable from local variable, so this.a = a possible
		// so on code execution, this is replace by object handler
	}
	void setBalance(double balance) {
		this.balance = balance;
	}
	void setCustomerName(String name) {
		this.customerName = name;
	}
	void setEmail(String email) {
		this.email = email;
	}
	void setPhoneNumber(long number) {
		this.phoneNumber = number;
	}

	// getters
	long getAccountNumber() {
		return this.accountNumber;
	}
	double getBalance() {
		return this.balance;
	}
	String getCustomerName() {
		return this.customerName;
	}
	String getEmail() {
		return this.email;
	}
	long getPhoneNumber() {
		return this.phoneNumber;
	}

	void deposit(double money) {
		this.balance += money;
	}

	void withdraw(double money) {
		if (this.balance - money < 0) {
			this.balance -= money;
		}
	}
}
