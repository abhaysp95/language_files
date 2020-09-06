// why linkedlist

package practice.udemy_tut.section8.linked_list;

import java.util.ArrayList;

public class Main {
	public static void main(String[] args) {
		Customer customer = new Customer("Tim", 923.92);
		Customer anotherCustomer;
		// pointing anotherCustomer to customer object
		anotherCustomer = customer;
		anotherCustomer.setBalance(2903.29);
		System.out.println("Name: " + customer.getName() + " and balance: " + customer.getBalance());

		System.out.println("---------------------");

		ArrayList<Integer> intList = new ArrayList<Integer>();
		intList.add(1);
		intList.add(3);
		intList.add(4);

		for (int i: intList) {
			System.out.println(i);
		}

		System.out.println("---------------------");

		intList.add(1, 2);  // adding 2 in 1st position
		for (int i: intList) {
			System.out.println(i);
		}

		// A lot of manipulation or movement is going on. If something is added
		// in between rest of the thing is shifted down and same for up, this
		// slows down the things

		// In linkedlist in java, if a object is no longer being used, it'll be
		// destroyed by java garbage collection mechanism

		System.out.println("---------------------");

		LinkedListDemo lldemo = new LinkedListDemo("Banaras");
		lldemo.addPlace("Merath");
		lldemo.addPlace("Chhatarpur");
		lldemo.addPlace("Panna");
		lldemo.addPlace("Goa");
		lldemo.addPlace("Mumbai");
		lldemo.addPlace("Bhuj");

		lldemo.printListOfPlace();

		System.out.println("---------------------");

		lldemo.addPlace("Gangtok", 2);
		lldemo.addPlace("Pune", 7);
		lldemo.printListOfPlace();

		System.out.println("---------------------");

		lldemo.removePlace(8);
		lldemo.printListOfPlace();

		System.out.println("---------------------");

		// add place in lexographicall order
		lldemo.putInOrder(lldemo.getList(), "Amethi");
		lldemo.putInOrder(lldemo.getList(), "Kolkata");
		lldemo.putInOrder(lldemo.getList(), "Kolkata");
		// you can use this method to populate the linkedlist at starting too
		lldemo.printListOfPlace();

		System.out.println("---------------------");

		lldemo.visitPlaces(lldemo.getList());
	}
}
