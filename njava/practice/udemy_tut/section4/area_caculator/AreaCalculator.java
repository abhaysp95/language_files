public class AreaCalculator {
	public static double area(double radius) {
		if (radius < 0) {
			return -1;
		}
		return Math.PI * radius * radius;
	}
	public static double area(double length, double breadth) {
		if (length < 0 || breadth < 0) {
			return -1;
		}
		return length * breadth;
	}
}
