package exception_with_inheritance;

class EvenNumException extends Exception {
	private int numer, denom;

	EvenNumException(int numer, int denom) {
		this.numer = numer;
		this.denom = denom;
	}

	@Override
	public String toString() {
		return "From EvenNumException:\n" + numer + " / " + denom;
	}
}

class DivisibleBy4Exception extends EvenNumException {
	private int numer, denom;

	DivisibleBy4Exception(int numer, int denom) {
		super(numer, denom);
		this.numer = numer;
		this.denom = denom;
	}

	@Override
	public String toString() {
		return "From DivisibleBy5Exception:\n" + numer + " / " + denom;
	}
}

class ShowExceptions {
	public void testException() {
		int[] numer = {3, 11, 12, 9, 94, 16, 45, 7, 19, 24, 32};
		int[] denom = {7, 0, 1, 0, 4, 8, 3, 9};

		// print numer and denom
		System.out.println("Numer:");
		for (int ele: numer) {
			System.out.print(ele + "\t");
		}
		System.out.println("\n");
		System.out.println("Denom:");
		for (int ele: denom) {
			System.out.print(ele + "\t");
		}
		System.out.println("\n");

		try {
			for (int i = 0; i < numer.length; ++i) {
				try {
					if (numer[i] % 4 == 0) {
						throw new DivisibleBy4Exception(numer[i], denom[i]);
					}
					if (numer[i] % 2 == 0) {
						throw new EvenNumException(numer[i], denom[i]);
					}
					System.out.println("Divide: " + numer[i] + " / " +
							denom[i] + " = " + numer[i] / denom[i]);
				}
				catch (ArithmeticException ae) {
					System.out.println("Can't divide by Zero\n" + ae.getMessage());
				}
				catch (DivisibleBy4Exception dbe) {
					System.out.println("In DivisibleBy4Exception catch block");
					System.out.println(dbe);
				}
				catch (EvenNumException ene) {
					System.out.println("In EvenNumException catch block");
					System.out.println(ene);
				}
				//catch (DivisibleBy4Exception dbe) {
					//System.out.println(dbe);
				//}
				// since the above exception is subclass of the EvenNumException,
				// it's already handled by the parent class, if you want to
				// handle it specifically, specify it above the parent class exception
			}
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("Nothing to divide:\n" + aie.getMessage());
		}
	}

	public static void main(String[] args) {
		ShowExceptions ob = new ShowExceptions();
		ob.testException();

		System.out.println("\n--------------------------\n");

		int[] numer = {3, 11, 12, 9, 94, 16, 45, 7, 19, 24, 32};
		int[] denom = {7, 0, 1, 0, 4, 8, 3, 9};

		// print numer and denom
		System.out.println("Numer:");
		for (int ele: numer) {
			System.out.print(ele + "\t");
		}
		System.out.println("\n");
		System.out.println("Denom:");
		for (int ele: denom) {
			System.out.print(ele + "\t");
		}
		System.out.println("\n");

		try {
			for (int i = 0; i < numer.length; ++i) {
				try {
					if (numer[i] % 4 == 0) {
						throw new DivisibleBy4Exception(numer[i], denom[i]);
					}
					if (numer[i] % 2 == 0) {
						throw new EvenNumException(numer[i], denom[i]);
					}
					System.out.println("Divide: " + numer[i] + " / " +
							denom[i] + " = " + numer[i] / denom[i]);
				}
				catch (ArithmeticException ae) {
					System.out.println("Can't divide by Zero\n" + ae.getMessage());
				}
				//catch (DivisibleBy4Exception dbe) {
					//System.out.println("In DivisibleBy4Exception catch block");
					//System.out.println(dbe);
				//}
				// Not using the above block just to see if the parent excpetion
				// block catches the exception of child
				catch (EvenNumException ene) {
					/* now, for child class, type of parent class for object
					 * will work, and "ene" will recieve the object for
					 * DivisibleBy4Exception() child class, so "ene" will print
					 * "toString()" of child class */
					System.out.println("In EvenNumException catch block");
					System.out.println(ene);
				}
				//catch (DivisibleBy4Exception dbe) {
					//System.out.println(dbe);
				//}
				// since the above exception is subclass of the EvenNumException,
				// it's already handled by the parent class, if you want to
				// handle it specifically, specify it above the parent class exception
			}
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("Nothing to divide:\n" + aie.getMessage());
		}
	}
}
