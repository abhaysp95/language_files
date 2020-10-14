// Find the solution to a quadratic equation

class Quadratic {
	public static void main(String[] args) {
		// quadratic equation to solve: 4x^2 + x - 3 = 0, for x
		double a = 4, b = 1, c = -3, x = 0;

		// first solution
		x = (-b + Math.sqrt(Math.pow(b, 2) - 4 * a * c)) / (2 * a);
		System.out.println("First solution: " + x);

		// second solution
		x = (-b - Math.sqrt(Math.pow(b, 2) - 4 * a * c)) / (2 * a);
		System.out.println("First solution: " + x);
	}
}

// first, this is unwieldy expression, having to specify the class name each
// time pow() and sqrt()(or any other java's math metohds) are used can
// become tedious
