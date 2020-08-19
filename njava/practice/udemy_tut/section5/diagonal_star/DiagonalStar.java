public class DiagonalStar {
	public static void main(String args[]) {
		System.out.println("For 5: ");
		printSquareStar(5);
		System.out.println("For -5: ");
		printSquareStar(-5);
		System.out.println("For 7: ");
		printSquareStar(7);
		System.out.println("For 8: ");
		printSquareStar(8);
	}

	public static void printSquareStar(int number) {
		if (number >= 5) {
			for (int i = 0; i < number; ++i) {
				for (int j = 0; j < number; ++j) {
					if ( i == 0 || j == 0 || i == j || i == number - 1 || j == number - 1 || i + j == number - 1) {
						System.out.print("*");
					}
					else {
						System.out.print(" ");
					}
				}
				System.out.println();
			}
		}
		else {
			System.out.println("Invalid Value");
		}
	}
}
