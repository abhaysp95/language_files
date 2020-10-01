import java.util.Scanner;
import java.math.BigInteger;

public class Solution {
	public static void main(String[] args) {
		BigInteger big = new BigInteger("1");
		Scanner scan = new Scanner(System.in);
		BigInteger fnum = scan.nextBigInteger();
		BigInteger snum = scan.nextBigInteger();

		BigInteger add;
		BigInteger mul;
		add = fnum.add(snum);
		mul = fnum.multiply(snum);
		System.out.println(add.toString());
		System.out.println(mul.toString());
	}
}
