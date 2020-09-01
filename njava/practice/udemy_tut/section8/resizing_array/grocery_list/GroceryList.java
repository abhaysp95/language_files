// using ArrayList to do operation in GroceryList

package practice.udemy_tut.section8.resizing_array.grocery_list;

import java.util.ArrayList;

public class GroceryList {
	private ArrayList<String> groceryList = new ArrayList<String>();

	public void addItem(String item) {
		groceryList.add(item);
	}

	public void printGroceryList() {
		System.out.println("Size of groceryList is: " + groceryList.size());
		System.out.println("Items in groceryList: ");
		for (int i = 0; i < groceryList.size(); ++i) {
			System.out.println("#" + (i + 1) + ": " + groceryList.get(i));
		}
	}

	public void modifyGroceryList(int pos, String newItem) {
		groceryList.set(pos - 1, newItem);
		System.out.println("Updated on position " + pos + " to " + newItem);
	}

	public void removeGroceryItem(int pos) {
		System.out.println("Removeing item " + groceryList.get(pos) + " from list");
		groceryList.remove(pos - 1);
	}

	public void findGroceryItem(String item) {
		boolean exists = groceryList.contains(item);
		System.out.println("If contains: " + exists);

		int position = groceryList.indexOf(item);  // returns -1 if not found
		if (position >= 0) {
			System.out.println("Found item " + item + " at position " + (position + 1));
		}
	}
}
