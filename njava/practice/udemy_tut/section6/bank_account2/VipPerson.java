package com.bankaccount;


class VipPerson {
	private String name;
	private double creditLimit;
	private String email;
	public VipPerson() {
		// this() here is calling another constructor(3rd one)
		this("Default Name", 50000.00, "Default Email");
	}
	// experimental
	public VipPerson(double creditLimit) {
		this("This is Name", creditLimit);
		// so this() will call another constructor which has matching number of parameters to same of this()'s arguments'
	}
	//public VipPerson(String name, double creditLimit) {
		//this(name, creditLimit, "default email");
	//}
	public VipPerson(String name, double creditLimit, String email) {
		this.name = name;
		this.creditLimit = creditLimit;
		this.email = email;
	}
	public VipPerson(String name, double creditLimit) {
		this.name = name;
		this.creditLimit = creditLimit;
	}

	// getters
	String getName() {
		return this.name;
	}
	double getCreditLimit() {
		return this.creditLimit;
	}
	String getEmail() {
		return this.email;
	}

	// setter (created because of second constructor)
	void setEmail(String email) {
		this.email = email;
	}
}
