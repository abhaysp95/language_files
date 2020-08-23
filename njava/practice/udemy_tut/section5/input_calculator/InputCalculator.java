import java.util.Scanner;

public class InputCalculator {
	public static void main(String args[]) {
		double sum = 0, avg = 0;
		double enteredNumber = 0;
		boolean flag = true;

		Scanner scan = new Scanner(System.in);
		while (true) {
			if(scan.hasNextDouble()) {  // Double does also take Int
				enteredNumber = scan.nextDouble();
				if (flag) {
					sum = avg = enteredNumber;
					flag = false;
				}
				else {
					sum += enteredNumber;
					avg = (avg + enteredNumber) / 2;
				}
			}
			else {
				System.out.println("SUM = " + sum + " AVG = " + avg);
				break;
			}
			scan.nextLine();
		}
		scan.close();
	}
}
