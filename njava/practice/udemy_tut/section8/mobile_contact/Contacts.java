package practice.udemy_tut.section8.mobile_contact;

import java.util.ArrayList;
import java.util.Scanner;

public class Contacts {
	private ArrayList<String> contactNames = new ArrayList<String>();
	private ArrayList<Long> contactNumbers = new ArrayList<Long>();
	private Scanner scan = new Scanner(System.in);

	public void addContact(String name, long number) {
		contactNames.add(name);
		contactNumbers.add(number);
	}

	public void printAllContact() {
		System.out.println("Printing all contact");
		for (int i = 0; i < contactNames.size(); ++i) {
			System.out.println(contactNames.get(i) + "\t" + contactNumbers.get(i));
		}
	}

	public void updateExistingContact(String name) {
		int position  = findContact(name);
		if (position >= 0) {
			System.out.println("Contact exist. Enter what you want to change:");
			System.out.println("1. Name\n2. Number\n3. Name and Number");
			int choice = scan.nextInt();
			switch(choice) {
				case 1:
					System.out.println("Enter name you want to change: ");
					String name = scan.nextLine();
					updateContact(name);
					break;
				case 2:
					System.out.println("Enter current name: ");
					name = scan.nextLine();
					updateContact(name, false);
				case 3:
					System.out.println("Enter old name ");
					name = scan.nextLine();
					updateContact(name, true);
					break;
			}
		}
	}

	private void updateContact(String name) {
		int position = findContact(name);
		if (position >= 0) {
			System.out.println("Enter new name: ");
			String newName = scan.nextLine();
			contactNames.set(position, newName);
		}
		else {
			System.out.println("Name doesn't exist or wrong name entered");
		}
	}

	private void updateContact(String name, boolean flag) {
		if (flag) {
			int position = findContact(name);
			if (position >= 0) {
				System.out.println("Enter new name and contact info: ");
				String newName = scan.nextLine();
				long newNumber = scan.nextLong();
				scan.nextLine();
				contactNames.set(position, newName);
				contactNumbers.set(position, newNumber);
			}
			else {
				System.out.println("Name doesn't exist or wrong name entered");
			}
		}
		else {
			int position = findContact(name);
			if (position >= 0) {
				System.out.println("Enter the number");
				long newNumber = scan.nextLong();
				scan.nextLine();
				contactNumbers.set(position, newNumber);
			}
			else {
				System.out.println("Name doesn't exist or wrong name entered");
			}
		}
	}

	public long getContactNumber(String name) {
		int position = contactNames.indexOf(name);
		if (position >= 0) {
			return contactNumbers.get(position);
		}
		else {
			return -1;
		}
	}

	public void removeContact(String name) {
		int position = findContact(name);
		if (position >= 0) {
			contactNames.remove(position);
			contactNumbers.remove(position);
		}
	}

	public void findTheContact(String name) {
		int position = findContact(name);
		if (position >= 0) {
			System.out.println("Contact " + name + " exist and number is: " + contactNumbers.get(position));
		}
	}

	private int findContact(String name) {
		return contactNames.indexOf(name);
	}

}
