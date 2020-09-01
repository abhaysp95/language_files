package practice.udemy_tut.section8.resizing_array.grocery_list;

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
					System.out.println("Enter position and new Item to modify groceryList");
					int pos = scan.nextInt();
					scan.nextLine();
					item = scan.nextLine();
					groceryList.modifyGroceryList(pos, item);
					break;
				case 4:
					System.out.println("Enter the position to remove the element:");
					pos = scan.nextInt();
					groceryList.removeGroceryItem(pos);
					break;
				case 5:
					System.out.println("Enter the item to find if exist in groceryList:");
					item = scan.nextLine();
					groceryList.findGroceryItem(item);
					break;
				case 6:
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
}
