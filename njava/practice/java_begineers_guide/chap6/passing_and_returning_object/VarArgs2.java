// variable number of argument passing to methood(with overloading)

class VarArgs2 {
	static void vaTest(int ... v) {
		System.out.println("vaTest(int ...): " + v.length);
		System.out.println("Contents: ");
		for (int i = 0; i < v.length; ++i) {
			System.out.println(" arg " + i + ": " + v[i]);
		}
		System.out.println();
	}

	static void vaTest(boolean ... v) {
		System.out.println("vaTest(boolean ...): " + v.length);
		System.out.println("Contents: ");
		for (int i = 0; i < v.length; ++i) {
			System.out.println(" arg " + i + ": " + v[i]);
		}
		System.out.println();
	}

	static void vaTest(String msg, int ... v) {
		// ... is used to pass variable number of arguments to the method
		System.out.println("vaTest(String, int ...): " + msg + v.length);
		/* ... basically makes the argument accepting identifier a array of given type, also ... should be at last in the list of parameters */
		System.out.println("Contents: ");
		for (int i = 0; i < v.length; ++i) {
			System.out.println(" arg " + i + ": " + v[i]);
		}
		System.out.println();
	}
	public static void main(String[] args) {
		vaTest(1, 2, 3);
		vaTest("One arg: ", 10);
		vaTest("Three arg: ", 1, 2, 3);
		vaTest("No arg: ");
		vaTest(true, false, false, true);
		// vaTest();  // this is ambiguous because of overloading
	}
}
