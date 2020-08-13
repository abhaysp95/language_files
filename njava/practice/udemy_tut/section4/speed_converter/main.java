// main method to run speedConverter

public class main {
	public static void main(String[] args) {
		long result = speedConverter.toMilesPerHour(10.25);
		System.out.println("Result: " + result);

		// test another method
		speedConverter.printConversion(-5.6);
	}
}
