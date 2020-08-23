import java.util.Scanner;

public class MinAndMaxInput {
	public static void main(String args[]) {
		int min = 0, max = 0;
		int enteredNumber = 0;
		boolean firstFlag = true;  // or you can check for highest and lowest
		/* something like this
		   min = Integer.MIN_VALUE;
		   man = Integer.MAX_VALUE;
		   now no need for flag, every value entered will be greater/equal to min and lesser/equal to max
	   */
		Scanner scan = new Scanner(System.in);

		while (true) {
			System.out.println("Enter the integer: ");
			if (scan.hasNextInt()) {
				enteredNumber = scan.nextInt();
				if (firstFlag) {
					min = max = enteredNumber;
					firstFlag = false;  // much better than count
				}
				if (enteredNumber < min) {
					min = enteredNumber;
				}
				if (enteredNumber > max) {
					max = enteredNumber;
				}
			}
			else {
				System.out.println("Oops! Invalid Entry");
				System.out.println("Printing maximum and minimum entered till now:");
				System.out.println("Maximum: " + max + " and minimum " + min);
				break;
			}
			scan.nextLine();
		}
		scan.close();
	}
}
