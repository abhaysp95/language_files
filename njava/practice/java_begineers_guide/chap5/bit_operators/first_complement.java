// demonstration of bitwise not

class first_complement {
	public static void main(String[] args) {
		byte b = -34;
		for (int t = 128; t > 0; t >>>= 1) {
			// a right shift halves the value, while a left shift doubles
			// >>> is unsigned right shift or zero-filled right shift
			if ((b & t) != 0) {
				System.out.print("1 ");
			}
			else {
				System.out.print("0 ");
			}
		}
		System.out.println();
		// reverse all bits
		b = (byte) ~b;
		for (int t = 128; t > 0; t /= 2) {
			if ((b & t) != 0) {
				System.out.print("1 ");
			}
			else {
				System.out.print("0 ");
			}
		}
	}
}
