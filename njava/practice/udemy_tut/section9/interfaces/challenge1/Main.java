package practice.udemy_tut.section9.interfaces.challenge1;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Player Thor = new Player("Thor", 60, 75);
		System.out.println(Thor.toString());
		saveObject(Thor);
		Thor.setScore(75);
		Thor.setStrength(85);
		Thor.setWeapon("StormBreaker");
		saveObject(Thor);
		System.out.println(Thor);
		//loadOjbect(Thor);
		System.out.println(Thor);

		ISavable warewolf = new Monster("WareWolf", 30, 40);
		System.out.println("Strength: " + ((Monster) warewolf).getStrength());
		System.out.println(warewolf);
		saveObject(warewolf);
	}

	public static ArrayList<String> readValues() {
		ArrayList<String> values = new ArrayList<String>();
		Scanner scan = new Scanner(System.in);
		int index = 0;
		boolean quit = false;
		System.out.println("Choose\n" +
				"0. quit" + "\n" +
				"1. to enter string");

		while (!quit) {
			System.out.println("Choose one option: ");
			int choice = scan.nextInt();
			scan.nextLine();
			switch (choice) {
				case 0:
					System.out.println("Quiting!");
					quit = true;
					break;
				case 1:
					System.out.println("Give input: ");
					String inputString = scan.nextLine();
					values.add(index++, inputString);
					break;
			}
		}
		scan.close();
		return values;
	}

	public static void saveObject(ISavable objectToSave) {
		for (int i = 0; i < objectToSave.write().size(); ++i) {
			System.out.println("Saving " + objectToSave.write().get(i) + " to the disk");
		}
	}

	public static void loadOjbect(ISavable objectToLoad) {
		ArrayList<String> values = readValues();
		objectToLoad.read(values);
	}
}
