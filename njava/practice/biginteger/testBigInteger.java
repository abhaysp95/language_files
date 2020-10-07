import java.math.BigInteger;
import java.util.Scanner;

class Operation {
	Scanner scan = new Scanner(System.in);

	public BigInteger subtract(BigInteger num1, BigInteger num2) {
		System.out.println(
				"First num: " + num1 +
				"Second num: " + num2);
		BigInteger sub = num2.subtract(num1);
		return sub;
	}

	public BigInteger multiply() {
		System.out.println("Enter two very long numbers: ");
		BigInteger fnum = scan.nextBigInteger();
		BigInteger snum = scan.nextBigInteger();
		return fnum.multiply(snum);
	}

	public BigInteger divide() {
		System.out.println("Enter two very long numbers(first should be big then second num): ");
		scan.nextLine();  // clear out carraige return
		try {
			String s1 = scan.nextLine();
			String s2 = scan.nextLine();
			return (new BigInteger(s1).divide(new BigInteger(s2)));
		}
		catch (NumberFormatException ne) {
			System.out.println("Input not provided correctly");
		}
		return null;
	}
}

class Test {
	public static void main(String[] args) {
		BigInteger first = new BigInteger("23094820934");
		BigInteger second = new BigInteger("203948092349023");
		Operation op = new Operation();
		System.out.println("Subtract: " + op.subtract(first, second));
		System.out.println("Multiply: " + op.multiply());
		BigInteger div = op.divide();
		if (div != null) {
			System.out.println("Divide: " + div);
		}
	}
}
