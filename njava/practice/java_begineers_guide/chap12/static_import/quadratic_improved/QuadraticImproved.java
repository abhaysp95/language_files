// Use static import to bring sqrt() and pow() into view

// Two forms

/*
   import static pkg.type-name.static-member-name;
   import static pkg.type-name.*;
*/

import static java.lang.Math.sqrt;
import static java.lang.Math.pow;

public class QuadraticImproved {
	public static void main(String[] args) {
		double a = 4, b = 1, c = -3, x = 0;

		// first solution
		x = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		System.out.println("first solution: " + x);

		// second solution
		x = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		System.out.println("second solution: " + x);
	}
}
