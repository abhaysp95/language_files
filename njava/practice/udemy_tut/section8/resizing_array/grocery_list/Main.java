package practice.udemy_tut.section8.resizing_array.grocery_list;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.ListIterator;
import java.util.Scanner;

public class Main {
	private static Scanner scan = new Scanner(System.in);
	private static GroceryList groceryList = new GroceryList();

	public static void main(String[] args) {
		boolean quit = false;
		int choice = 0;
		printInstruction();
		while(!quit) {
			System.out.println("Enter the choice: ");
			choice = scan.nextInt();
			scan.nextLine();
			switch(choice) {
				case 0:
					printInstruction();
					break;
				case 1:
					groceryList.printGroceryList();
					break;
				case 2:
					System.out.println("Enter grocery item to add to list:\r");
					String item = scan.nextLine();
					groceryList.addItem(item);
					break;
				case 3:
					System.out.println("Enter old item and new item to interchange:\r");
					item = scan.nextLine();
					String newItem = scan.nextLine();
					groceryList.modifyGroceryList(item, newItem);
					break;
				case 4:
					System.out.println("Enter the item name to remove the element:");
					item = scan.nextLine();
					groceryList.removeGroceryItem(item);
					break;
				case 5:
					System.out.println("Enter the item to find if exist in groceryList:");
					item = scan.nextLine();
					boolean flag = groceryList.onFile(item);
					if (flag) {
						System.out.println("Search item exist on list");
					}
					else {
						System.out.println("Search item doesn't exist on list");
					}
					break;
				case 6:
					processArrayList();
					break;
				case 7:
					quit = true;
					break;
				default:
					System.out.println("Entered wrong choice");
			}
		}
	}

	public static void printInstruction() {
		System.out.println("0. Instruction is printed");
		System.out.println("1. Print GroceryList");
		System.out.println("2. Add item to list");
		System.out.println("3. Modify item in list");
		System.out.println("4. Remove item");
		System.out.println("5. Find grocery item");
		System.out.println("6. Exit");
	}

	public static void processArrayList() {
		ArrayList<String> newArray = new ArrayList<String>();
		newArray.addAll(groceryList.getGroceryList());
		// or to do at the time of declaration
		ArrayList<String> nextArray = new ArrayList<String>(groceryList.getGroceryList());

		System.out.println("Printing newArray using toString(): \n" + newArray.toString());
		System.out.println("\nPrintint nextArray: \n" + nextArray);

		System.out.println("\nUsing for loop");
		for (int i = 0; i < newArray.size(); ++i) {
			System.out.print(newArray.get(i) + "\n");
		}

		System.out.println("\nUsing for each loop:");
		for (String element: newArray) {
			System.out.print(element + "\t");
		}

		System.out.println("\nUsing iterator:");
		Iterator iter = newArray.iterator();
		while (iter.hasNext()) {
			System.out.print(iter.next() + "\t");  // iter.next() will give string
		}

		System.out.println("\nUsing list-iterator: ");
		ListIterator<String> litr = null;
		// it's not necessary to give type in <> to ListIterator
		// initializing ListIterator to null at first is necessary
		litr = newArray.listIterator();
		while (litr.hasNext()) {
			System.out.print(litr.next() + "\t");
		}


		// to change a ArrayList to normal array
		String[] myArray = new String[groceryList.getGroceryList().size()];  // initialize with proper size
		myArray = groceryList.getGroceryList().toArray(myArray);

		System.out.println("\n\nPrinting Array using loop");
		for (String element: myArray) {
			System.out.print(element + "\t");
		}

		System.out.println("\nPrinting using Arrays class");
		System.out.println(Arrays.toString(myArray));
	}
}
