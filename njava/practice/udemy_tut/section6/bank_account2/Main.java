package com.bankaccount;

public class Main {
	public static void main(String ...args) {
		// java automatically creates constructor for us(see below)
		// BankAccount work = new BankAccount(23894320L, 6389.00, "Andrew", "andrew@xyz.com", 990_2390_9239L);
		// you can also not use setters now, if not necessary
		BankAccount work = new BankAccount();  // so this() worked on constructor
		work.setCustomerName("Tony");
		System.out.println("Name: " + work.getCustomerName());
		work.setBalance(7839.80);
		System.out.println("Current balance: " + work.getBalance());
		work.withdraw(430.29);
		System.out.println("Current balance after withdrawal: " + work.getBalance());
		work.deposit(234.77);
		System.out.println("Current balance after deposit: " + String.format("%.2f", work.getBalance()));
		System.out.println("Email: " + work.getEmail());

		BankAccount work2 = new BankAccount(239402934L, "Garfield", "garfield@xyz.com");
		System.out.println("Name: " + work2.getCustomerName() +
				" Email: " + work2.getEmail() +
				" account number: " + work2.getAccountNumber() +
				" balance: " + work2.getBalance() +
				" get phone number: " + work2.getPhoneNumber()
				);

		// calling fisrt constructor
		VipPerson person1 = new VipPerson();
		System.out.println("Person1 name: " + person1.getName());
		System.out.println("Person1 creditLimit: " + person1.getCreditLimit());
		System.out.println("Person1 email: " + person1.getEmail());

		// calling third constructor
		//VipPerson person2 = new VipPerson("Tim Cook", 10000000.00);
		//System.out.println("Person2 name: " + person2.getName());
		//System.out.println("Person2 creditLimit: " + person2.getCreditLimit());
		//System.out.println("Person2 email: " + person2.getEmail());

		// calling fourth constructor
		VipPerson person3 = new VipPerson("Jeff Bezos", 100000000000000.00, "bezosunkown@amazon.in");
		System.out.println("Person3 name: " + person3.getName());
		System.out.println("Person3 creditLimit: " + person3.getCreditLimit());
		System.out.println("Person3 email: " + person3.getEmail());

		// calling second constructor
		VipPerson person4 = new VipPerson(2348923L);
		person4.setEmail("this is email");
		System.out.println("Person4 name: " + person4.getName());
		System.out.println("Person4 creditLimit: " + person4.getCreditLimit());
		System.out.println("Person4 email: " + person4.getEmail());
	}

}
