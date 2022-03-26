import java.util.Scanner;

class Solutions {
	Scanner scan = new Scanner(System.in);

	void solution1() {
		int a = scan.nextInt();
		int b = scan.nextInt();
		System.out.println(a + b + ", " + a * b);
	}

	void solution3() {
		double a = scan.nextDouble();
		double b = scan.nextDouble();
		System.out.println((int)(a * b));
	}

	void solution4() {
		System.out.println("Give name:");
		String name = scan.next();  // .next() will just take upto space
		System.out.println("Enter roll number:");
		int roll = scan.nextInt();
		scan.nextLine();  // consume '\n' etc.
		System.out.println("Enter interest:");
		String interest = scan.nextLine();
		System.out.println("Hey, my name is " + name +
				", and my roll number is " + roll +
				", and my field of interest are " + interest);
	}
}

public class InputByUser {
	public static void main(String... args) {
		Solutions sol = new Solutions();
		sol.solution4();
	}
}
