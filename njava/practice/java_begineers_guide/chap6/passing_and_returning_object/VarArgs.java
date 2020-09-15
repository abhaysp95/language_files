// variable number of argument passing to methood

class VarArgs {
	static void vaTest(String msg, int ... v) {
		// ... is used to pass variable number of arguments to the method
		System.out.println(msg + v.length);
		/* ... basically makes the argument accepting identifier a array of given type, also ... should be at last in the list of parameters */
		System.out.println("Contents: ");
		for (int i = 0; i < v.length; ++i) {
			System.out.println(" arg " + i + ": " + v[i]);
		}
		System.out.println();
	}
	public static void main(String[] args) {
		vaTest("One arg: ", 10);
		vaTest("Three arg: ", 1, 2, 3);
		vaTest("No arg: ");
	}
}
