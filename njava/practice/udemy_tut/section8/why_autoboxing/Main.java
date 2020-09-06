// why need autoboxing in java

import java.util.ArrayList;

class IntClass {
	private int number;

	IntClass() {
		this(0);
	}

	IntClass(int number) {
		this.number = number;
	}

	public int getNumber() {
		return this.number;
	}

	public void setNumber(int number) {
		this.number = number;
	}
}

public class Main {
	public static void main(String[] args) {
		// we can do this
		String[] strArray = new String[10];
		int[] intArray = new int[10];

		ArrayList<String> arrayListString = new ArrayList<String>();
		// but not do this
		// ArrayList<int> arrayListInt = new ArrayList<int>();

		// we can create a wrapper class for int, if we want
		ArrayList<IntClass> intClassArrayList = new ArrayList<IntClass>();
		intClassArrayList.add(new IntClass(10));
		System.out.println("Number from intClassArrayList: " + intClassArrayList.get(0).getNumber());
		// as .get(0) will return IntClass
		// change
		IntClass intClass = new IntClass();
		// now this thing below is done because line with intClassArrayList.set(0, intClass).setNumber(20); wasn't working
		// but doing the below lines made it work(don't know how though)
		IntClass checkIfClass = intClassArrayList.set(0, intClass);
		System.out.println("getting from checkIfClass: " + checkIfClass.getNumber());
		checkIfClass.setNumber(30);
		System.out.println("after setting from checkIfClass: " + checkIfClass.getNumber());
		// I want to set 20 now at index 0
		intClassArrayList.set(0, intClass).setNumber(20);
		System.out.println("Number from intClassArrayList: " + intClassArrayList.get(0).getNumber());

		// instead of wrapper class, other ways
		// Integer integer = new Integer(54); this is deprecated
		// Integer integer = new Integer("hello"); also deprecated

		System.out.println("---------------------------------");

		ArrayList<Integer> intArrayList = new ArrayList<Integer>();
		for (int i = 0; i <= 10; ++i) {
			// converting value of i(primitive type) to Integer class(valueOf returns Integer class here)
			//intArrayList.add((i + 1) * 10);  working
			intArrayList.add(Integer.valueOf((i + 1) * 10));  // this part here, is known as autoboxing
		}

		for (int i = 0; i <= 10; ++i) {
			// intValue() is converting back to int(primitive type) from Integer class
			//System.out.println(i + " --> " + intArrayList.get(i));  working
			System.out.println(i + " --> " + intArrayList.get(i).intValue());  // and this part is unboxing
		}

		Integer myIntValue = 56;  // technically this should not work, cause we needed to create object, but java is helping here
		// on compile time, the above line changes to Integer myIntValue = Integer.valueOf(56);
		// same for Double, Boolean, Character, Long and others
		int myInt = myIntValue;  // now this is changing the object to primitive type, how is this working? Again java is helping
		// the above is same to int myInt = myIntValue.intValue();

		// so now you should get why add(int) and get(int) were working

		System.out.println("---------------------------------");

		// let's try for double
		ArrayList<Double> doubleArrayList = new ArrayList<Double>();
		for (double i = 0.0; i < 5.0; i+=0.5) {
			// can also do, add(i) only
			doubleArrayList.add(Double.valueOf(i));
		}

		for (int i = 0; i < doubleArrayList.size(); ++i) {
			// can also use get(i) only
			System.out.println(i + " --> " + doubleArrayList.get(i).doubleValue());
		}
	}
}
