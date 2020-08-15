public class IntEqualityPrinter {
	public static void printEqual(int num1, int num2, int num3) {
		String output = "";
		if (num1 < 0 || num2 < 0 || num3 < 0) {
			output = "Invalid Value";
		}
		else if (num1 == num2 && num2 == num3) {
			output = "All numbers are equal";
		}
		else if (num1 != num2 && num2 != num3 && num3 != num1) {
			output = "All numbers are different";
		}
		else {
			output = "Neither all are equal or different";
		}
		System.out.println(output);
	}
}
