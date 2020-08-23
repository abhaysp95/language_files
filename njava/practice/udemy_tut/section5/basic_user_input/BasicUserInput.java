import java.util.Scanner;

public class BasicUserInput {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);  // scanner instance

		System.out.println("Enter your year of birth: ");

		boolean hasNextInt = scanner.hasNextInt();  // checks if the next input entered is a number(integer) and returns boolean

		if (hasNextInt) {
			int yearOfBirth = scanner.nextInt();
			// it's also doing Integer.parseInt() internally
			scanner.nextLine();

			System.out.println("Enter you name: ");
			String name = scanner.nextLine();

			int age = 2020 - yearOfBirth;

			if (age <= 0 || age > 100) {
				System.out.println("Invalid Value for age");
			}
			else {
				System.out.println("You are: " + name + " and you age is: " + age);
			}
		}
		else {
			System.out.println("Can't parse the input provided");
		}
		scanner.close();
	}
}
