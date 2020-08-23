import java.util.Scanner;

public class ReadNumberFromUser {
	public static void main(String args[]) {
		int count = 1, enteredNumber = 0, sum = 0;
		boolean flag = false;
		System.out.println("Enter 10 integers: ");

		Scanner scan = new Scanner(System.in);

		while (count <= 10) {
			System.out.println("Enter number #" + count + ": ");
			if (scan.hasNextInt()) {
				enteredNumber = scan.nextInt();
				System.out.println("You entered = " + enteredNumber);
				sum += enteredNumber;
			}
			else {
				System.out.println("Invalid entry, printing sum till now and exiting!");
				System.out.println("Sum is: " + sum);
				flag = true;
				break;
			}
			scan.nextLine();
			++count;
		}
		scan.close();
		if (!flag) {
			System.out.println("Sum is: " + sum);
		}
	}
}
