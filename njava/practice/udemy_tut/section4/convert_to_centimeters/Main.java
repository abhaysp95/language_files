// demonstration of method overloading

// Note:- Method overloading in java is not totally same as the function
// overloading in C++, cause function overloading in C++ can have same name
// function with same number of parameters but with different return type
// work too, but in java you have to have different number of parameter for
// the method to use method overloading, datatype of parameters different will also work, but only return of the method different will not

public class Main {
	public static void main(String args[]) {
		double first_function = calcFeetAndInchesToCentimeters(5, 20.5);
		if (first_function != -1) {
			System.out.println("To centimeters: " + first_function + " cm");
		}
		else {
			System.out.println("Invalid parameters passed.");
		}

		double second_function = calcFeetAndInchesToCentimeters(72.5);
		if (second_function != -1) {
			System.out.println("To centimeters: " + second_function + " cm");
		}
		else {
			System.out.println("Invalid parameters passed.");
		}
	}

	public static double calcFeetAndInchesToCentimeters(double feets, double inches) {
		if ((feets < 0) || (inches < 0 || inches > 12)) {
			return -1;
		}
		double to_centimeters = 0;
		to_centimeters = feets * (12 * 2.54);
		to_centimeters += (inches * 2.54);

		return to_centimeters;
	}

	public static double calcFeetAndInchesToCentimeters(double inches) {
		if (inches < 0) {
			return -1;
		}
		double tofeets = 0, remaining_inches = 0;
		tofeets = (int)inches / 12;
		remaining_inches = inches % 12;
		System.out.println("Feets: " + tofeets + " feets and remaining inches are: " + remaining_inches + " inches");
		return calcFeetAndInchesToCentimeters(tofeets, remaining_inches);
	}
}
