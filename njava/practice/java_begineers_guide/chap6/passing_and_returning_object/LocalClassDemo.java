// Use ShowBits as a local class

class LocalClassDemo {
	public static void main(String[] args) {
		class ShowBits {
			int numbits;

			ShowBits(int n) {
				this.numbits = n;
			}

			void show (long val) {
				long mask = 1;
				mask <<= numbits - 1;
				int spacer = 0;
				for ( ; mask != 0; mask >>>= 1 ) {
					if ((mask & val) != 0) {
						System.out.print("1");
					}
					else {
						System.out.print("0");
					}
					spacer++;
					if ((spacer % 8) == 0) {
						System.out.print(" ");
					}
				}
				System.out.println();
			}
		}
		for (byte b = 0; b < 10; b++) {
			ShowBits byteVal = new ShowBits(8);
			System.out.print(b + " in binary: ");
			byteVal.show(b);
		}

		for (byte b = 111; b < 121; b++) {
			ShowBits byteVal = new ShowBits(16);
			System.out.print(b + " in binary: ");
			byteVal.show(b);
		}
	}
}
