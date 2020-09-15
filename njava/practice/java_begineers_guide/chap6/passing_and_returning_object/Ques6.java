// Reverse a string

class Reverse {
	private String gotString;

	Reverse (String gotString) {
		this.gotString = gotString;
	}

	String getString() {
		return this.gotString;
	}

	/*void print() {
		System.out.println(gotString.toCharArray()[3] + "" + gotString.toCharArray()[5]);
		// or else it'll change it in int and add them
	}*/

	/*void reverseString() {
		char[] stringArray = gotString.toCharArray();
		for (char ch: stringArray) {
			if (ch / 2 == 0) {
				ch = 'A';
			}
			System.out.print(ch + " ");
		}
	}*/
	// but can't use the above one because, forEach array is readOnly
	// above method was tested

	void reverseString() {
		char[] stringArray = this.gotString.toCharArray();
		for (int i = 0; i < stringArray.length / 2; ++i) {
			System.out.println("Swapping + " + stringArray[i] + " and " + stringArray[stringArray.length - 1 -i]);
			char ch = stringArray[i];
			stringArray[i] = stringArray[stringArray.length - 1 -i];
			stringArray[stringArray.length - 1 -i] = ch;
		}
		System.out.println("Reversed array: ");
		for (int i = 0; i < stringArray.length; ++i) {
			System.out.print(stringArray[i]);
		}
		System.out.println();
		this.gotString = stringArray.toString();  // problem is here
	}
}

class Ques6 {
	public static void main(String[] args) {
		Reverse rvrs = new Reverse("gotString");
		System.out.println("String passed: " + rvrs.getString());
		//rvrs.print();
		rvrs.reverseString();
		System.out.println("String reversed: " + rvrs.getString());
	}
}
