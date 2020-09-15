// Uppercase letters

class ChangeCase {
	public static void main(String[] args) {
		upperCase();
		lowerCase();
	}

	public static void upperCase() {
		char ch = Character.MIN_VALUE;
		for (int i = 0; i < 10; i++) {
			ch = (char) ('a' + i);
			System.out.print(ch);
			// this statement turns off the 6th bit
			ch = (char) ((int) ch & 65503);  // ch is now uppercase
			System.out.print(ch + " ");
			// just like that
			//if ((status & 8) != 0) System.out.println("bit 4 is on");
			// that will tell you if the 4th bit was on or not as 8 => 1000
		// 65503 is 1111 1111 1101 1111 in binary, thus & operation changes 6th bit only
		}
	}

	public static void lowerCase() {
		char ch = Character.MIN_VALUE;
		for (int i = 0; i < 10; i++) {
			ch = (char) ('A' + i);
			System.out.print(ch);
			// this statement turns on the 6th bit
			ch = (char) ((int) ch | 32);  // ch is now uppercase
			System.out.print(ch + " ");
		}
	}
}
