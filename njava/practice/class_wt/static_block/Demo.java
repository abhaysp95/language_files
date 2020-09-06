class Demo {
	// first JVM executes static block and then static method
	static {
		System.out.println("Static Block");
	}
	public static void main(String args[]) {
		System.out.println("Main method");
	}

}
/* static members = They are loaded at the time of loading class defination without making a object for the static member */
