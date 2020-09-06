package practice.udemy_tut.section8.mobile_contact;

import java.util.Scanner;

public class Mobile {

	private static Scanner scan = new Scanner(System.in);
	private static Contacts contacts = new Contacts();

	public static void main(String[] args) {
		boolean flag = false;

		while(!flag) {
			System.out.println("Enter choice: ");
			printChoice();
			int choice = scan.nextInt();
			scan.nextLine();
			switch(choice) {
				case 1:
					addContact();
					break;
				case 2:
					getNumber();
			}
		}
	}

	public static void printChoice() {
		System.out.println("0. Print All");
		System.out.println("1. Add Name and Number");
		System.out.println("2. Get number for name");
	}

	public static void addContact() {
		System.out.println("Enter name and number:");
		String name = scan.nextLine();
		long number = scan.nextLong();
		scan.nextLine();
		contacts.addContact(name, number);
	}

	public static void getNumber() {
		System.out.println("Enter the name whose number you wanna find out:");
		String name = scan.nextLine();
		long number = contacts.getContactNumber(name);
		if (number != -1) {
			System.out.println("Number of " + name + " is: " + number);
		}
		else {
			System.out.println("No number for this contact \"" + name + "\"");
		}
	}
}
