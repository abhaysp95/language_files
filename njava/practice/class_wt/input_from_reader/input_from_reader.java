// taking input from bufferedreader

import java.io.InputStreamReader;
import java.io.BufferedReader;


class Calculator {
	public void add(int x, int y) {
		// can call static method from non-static but not vice-versa
		int sum = printResult(x + y);
		System.out.println("Sum is: " + sum);
	}

	public static void main(String[] args) {
		Calculator calc = new Calculator();
		try {
			//BufferedReader bufr = new BufferedReader(new InputStreamReader(System.in));
			//int x = Integer.parseInt(bufr.readLine());
			//int y = Integer.parseInt(bufr.readLine());
			int x = Integer.parseInt(args[0]);
			int y = Integer.parseInt(args[1]);
			calc.add(x, y);
		}
		catch (Exception E) {
			System.out.println("Exception: " + E);
		}
		// using calc.add(x, y) will give error as x and y will not have scope out of try block
		doAddition(calc);
	}

	public static void doAddition(Calculator calc) {
		try {
			BufferedReader bufr = new BufferedReader(new InputStreamReader(System.in));
			int x = Integer.parseInt(bufr.readLine());
			int y = Integer.parseInt(bufr.readLine());
			calc.add(x, y);
		}
		catch (Exception E) {
			System.out.println("Exception: " + E);
		}
	}

	public static int printResult(int sum) {
		return sum;
	}
}

/* the difference between BufferedReader and using Scanner is that BufferedReader doesn't have the problem of having `Carriage Return` in input buffer which is the problem with Scanner's object */

/* to not use object calc make the add method static */

/* math.add(); this works because the add() is defined there as static type so we not need to create the object for this */
