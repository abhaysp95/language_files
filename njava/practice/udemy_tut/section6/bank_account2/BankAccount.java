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
	// you may or may not give public depends on how you're using it
	public BankAccount() {
		// this says that if you are trying to create an object of this class without giving me any parameters then these are the parameters I'll use
		// you may wanna do this, to make sure when the class is created with all the fields set
		this(820394L, 329.00, "Name", "Email", 29034020923L);
		// this this() line called the other constructor first
		// if there's not another constructor if you want to use this() then error will be generated
		/* error: constructor BankAccount in class BankAccount cannot be applied to given types; */
		System.out.println("constructor for BankAccount class called");
	}
	/* now the this() line above in constructor should be the very first line of the constructor */

	// we can overloaded provided we change the number of parameters
	// see that in bank_account
	public BankAccount(long accountNumber, double balance, String customerName, String email, long phoneNumber) {
		this.accountNumber = accountNumber;
		this.balance = balance;
		this.customerName = customerName;
		this.email = email;
		this.phoneNumber = phoneNumber;
		System.out.println("constructor with parameters called");
	}

	public BankAccount(long accountNumber, String name, String email) {
		this(accountNumber, 500.00, name, email, 92034092343L);
	}

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
		if (this.balance - money >= 0) {
			this.balance -= money;
		}
	}
}
