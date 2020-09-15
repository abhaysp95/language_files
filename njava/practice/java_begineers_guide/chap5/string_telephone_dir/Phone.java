// a simple automated telephone directory

class Phone {
	public static void main(String[] args) {
		boolean status = false;
		String[][] numbers = {
			{ "Tom", "555-2343" },
			{ "Mary", "234-2394" },
			{ "Jon", "942-9834" },
			{ "Rachel", "555-1004" }
		};
		if (args.length != 1) {
			System.out.println("Usage: java Phone <name>");
		}
		else {
			for (String[] detail: numbers) {
				if (detail[0].equals(args[0])) {
					System.out.println(detail[0] + ": " + detail[1]);
					status = true;
					break;
				}
			}
		}
		if (!status) {
			System.out.println("Name not found");
		}

		System.out.println("-----------------");
		// local variable type interface with a user-defined class type
		var vM = new Phone();
		vM.varMethod();
	}

	/* Type interface with local variables */
	// support from jdk10(but not known much)
	private void varMethod() {
		var x = 10.0;  // var is of type double
		var myArray = new int[10];

		for (int i = 0; i < 10; ++i) {
			myArray[i] = (i + 1) * 10;
		}

		System.out.println("Printing array: ");
		for (int i = 0; i < 10; ++i) {
			System.out.println(myArray[i]);
		}
	}
	// this "var" can be used with loops and stuff, var has some restrication with normal array declaration though
}
