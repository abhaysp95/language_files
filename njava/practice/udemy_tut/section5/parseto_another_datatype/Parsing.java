// parsing methods

public class Parsing {
	public static void main(String args[]) {
		// String age = "10.2", nextAge = "15.4";
		String age = "10", nextAge = "15";
		System.out.println("Adding ages: " + age + nextAge);

		// parsing string to int
		int sum = Integer.parseInt(age) + Integer.parseInt(nextAge);
		System.out.println("Adding ages: " + sum);

		// parsing string to double
		double sumd = Double.parseDouble(age) + Double.parseDouble(nextAge);
		System.out.println("Adding ages(double): " + sumd);
	}
}
