// display binary representation of given int

class ShowBitsShift {
	public static void main(String[] args) {
		ShowBitsClass b = new ShowBitsClass(8);
		ShowBitsClass i = new ShowBitsClass(32);
		ShowBitsClass li = new ShowBitsClass(64);
		System.out.println("123 in binary: ");
		b.show(123L);
		System.out.println("\n7987 in binary: ");
		i.show(87987);
		System.out.println("\n2376587668 in binary: ");
		li.show(2376587668l);
	}
}

class ShowBitsClass {
	int numBits;

	ShowBitsClass(int num) {
		this.numBits = num;
	}

	void show(long num) {
		long mask = 1;
		int spacer = 0;
		// left-shift a 1 into the proper position
		mask <<= numBits - 1;
		System.out.println("Mask: " + mask);
		for (; mask != 0; mask >>>= 1) {
			if ((num & mask) != 0) {
				System.out.print("1");
			}
			else {
				System.out.print("0");
			}
			spacer++;
			if (spacer % 8 == 0) {
				System.out.print(" ");
				spacer = 0;
			}
		}
		System.out.println();
	}
}
