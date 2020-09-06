// using ArrayList to do operation in GroceryList

package practice.udemy_tut.section8.resizing_array.grocery_list;

import java.util.ArrayList;

public class GroceryList {
	private ArrayList<String> groceryList = new ArrayList<String>();

	public ArrayList<String> getGroceryList() {
		return groceryList;
	}

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

	public void modifyGroceryList(String item, String newItem) {
		int position = findGroceryItem(item);
		if (position >= 0) {
			modifyGroceryList(position, newItem);
		}
		else {
			System.out.println("Item entered doesn't exist");
		}
	}

	private void modifyGroceryList(int pos, String newItem) {
		groceryList.set(pos, newItem);
		System.out.println("Updated on position " + (pos + 1) + " to " + newItem);
	}

	public void removeGroceryItem(String item) {
		int position = findGroceryItem(item);
		if (position >= 0) {
			removeGroceryItem(position);
		}
		else {
			System.out.println("Item entered doesn't exist");
		}
	}

	private void removeGroceryItem(int pos) {
		System.out.println("Removeing item " + groceryList.get(pos) + " from list");
		groceryList.remove(pos);
	}

	//public void findGroceryItem(String item) {
		//boolean exists = groceryList.contains(item);
		//System.out.println("If contains: " + exists);

		//int position = groceryList.indexOf(item);  // returns -1 if not found
		//if (position >= 0) {
			//System.out.println("Found item " + item + " at position " + (position + 1));
		//}
	//}

	private int findGroceryItem(String item) {
		return groceryList.indexOf(item);
	}

	public boolean onFile(String searchItem) {
		int position = findGroceryItem(searchItem);
		if (position >= 0) {
			return true;
		}
		else {
			return false;
		}
	}
}
