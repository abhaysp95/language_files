class BasicRecursion {
	static int getFactorial(int n) {
		if (n <= 1) {
			return 1;
		}
		return BasicRecursion.getFactorial(n - 1) * n;
	}

	static int getFibonacci(int start, int size) {
		if (size <= start) {
			return 1;
		}
		return BasicRecursion.getFibonacci(start, size - 1) + BasicRecursion.getFibonacci(start, size - 2);
	}
}

public class Main {
	public static void main(String[] args) {
		int fact = BasicRecursion.getFactorial(5);
		System.out.println("Factorial res: " + fact);
		int fib = BasicRecursion.getFibonacci(1, 5);
		System.out.println("Fibonacci res: " + fib);
	}
}



//int fact;
//if (n > 1) {
	//fact = Factorial.getFactorial(n -1 ) * n;
//}
//else {
	//fact = 1;
//}
//return fact;

