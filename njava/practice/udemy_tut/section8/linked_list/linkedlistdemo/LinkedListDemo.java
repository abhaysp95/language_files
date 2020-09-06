package practice.udemy_tut.section8.linked_list;

import java.util.Iterator;
import java.util.ListIterator;
import java.util.LinkedList;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class LinkedListDemo {
	private LinkedList<String> placesToVisit = new LinkedList<String>();

	public LinkedListDemo(String place) {
		this.placesToVisit.add(place);
	}

	public LinkedList<String> getList() {
		return this.placesToVisit;
	}

	public void addPlace(String place) {
		this.placesToVisit.add(place);
	}

	public void addPlace(String place, int position) {
		this.placesToVisit.add(position, place);
	}

	public void removePlace(int position) {
		this.placesToVisit.remove(position);
	}

	public void printListOfPlace() {
		Iterator<String> place = placesToVisit.iterator();
		// automatically goes to the very first entry stored in iterator
		while (place.hasNext()) {
			System.out.println("Visting: " + place.next());
		}
	}

	public boolean putInOrder(LinkedList<String> linkedList, String place) {
		ListIterator<String> stringListIterator = linkedList.listIterator();
		while (stringListIterator.hasNext()) {
			int comparision = stringListIterator.next().compareTo(place);
			if (comparision == 0) {
				System.out.println(place + " already exist in list.");
				return false;
			}
			// cause it's comparing already in list to the new one
			// and already in is greater than the new one, so +ve
			else if (comparision > 0) {
				// cause it has already moved to next few lines above
				stringListIterator.previous();
				// now this is working because java's linkedList is like
				// doubly linkedList, so it stores reference for next as well
				// as previous element
				stringListIterator.add(place);
				return true;
			}
			else if (comparision < 0) {
				// move to next city
			}
		}
		// now if none of the above case matched till last then simply add to last
		stringListIterator.add(place);
		return true;
	}

	public void visitPlaces(LinkedList<String> cities) {
		// you can use Scanner too but this automatically resolve the problem
		// of carriage return in input buffer
		BufferedReader bufr = new BufferedReader(new InputStreamReader(System.in));
		try {
			boolean quit = false;
			boolean goingForward = true;
			ListIterator<String> listIterator = cities.listIterator();

			// check first if linkedlist is empty or not
			if (cities.isEmpty()) {
				System.out.println("No ciites in the itenerary");
			}
			else {
				System.out.println("Now visiting: " + listIterator.next());
				printOptions();
			}

			while (!quit) {
				System.out.println("Enter your option:\r");
				int choice = Integer.parseInt(bufr.readLine());
				switch (choice) {
					case 0:
						System.out.println("Holidays(Vacation) are over now");
						quit = true;
						break;
					case 1:
						// coming from back, or when goingForward = false
						if (!goingForward) {
							if (listIterator.hasNext()) {
								listIterator.next();
							}
							goingForward = true;
						}
						if (listIterator.hasNext()) {
							System.out.println("Now visting: " + listIterator.next());
						}
						else {
							System.out.println("Reached to end of destination");
							goingForward = false;  // reached last
						}
						break;
					case 2:
						// when coming from forward
						if (goingForward) {
							if (listIterator.hasPrevious()) {
								listIterator.previous();
							}
							goingForward = false;
						}
						if (listIterator.hasPrevious()) {
							System.out.println("Now visting: " + listIterator.previous());
						}
						else {
							System.out.println("Journey is yet to start");
							goingForward = true;  // at the start
						}
						break;
					case 3:
						printOptions();
						break;
					default:
						System.out.println("Provide correct option");
				}
			}
		}
		catch (Exception E) {
			System.out.println("Exception: " + E);
		}
	}

	private void printOptions() {
		System.out.println("0: End the journey");
		System.out.println("1: Move to next destination");
		System.out.println("2: Move to previous destination");
		System.out.println("3: Print option list");
	}
}


/* the forward and backward problem in the visit method() is that, linkedlist
 * hops in between the elements of the list, so if we moved next and then
 * previous and then again next and then previous and then again next, this
 * will never end and will point to the same value, something related to
 * tortoise-hare algoright problem */
