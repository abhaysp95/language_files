public class Main {
	public static void main(String args[]) {
		int sum1 = SumOddRange.sumOdd(1, 100);
		int sum2 = SumOddRange.sumOdd(-1, 100);
		int sum3 = SumOddRange.sumOdd(100, 100);
		int sum4 = SumOddRange.sumOdd(13, 13);
		int sum5 = SumOddRange.sumOdd(100, -100);
		int sum6 = SumOddRange.sumOdd(100, 1000);

		System.out.println("Sum1 is: " + sum1);
		System.out.println("Sum2 is: " + sum2);
		System.out.println("Sum3 is: " + sum3);
		System.out.println("Sum4 is: " + sum4);
		System.out.println("Sum5 is: " + sum5);
		System.out.println("Sum6 is: " + sum6);
	}
}
