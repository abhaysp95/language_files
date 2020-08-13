public class main {
	public static void main(String[] argv) {
		// boolean returntype = BarkingDog.shouldWakeUp(true, 1);
		boolean returntype = BarkingDog.shouldWakeUp(false, 23);
		if (returntype) {
			System.out.println("true");
		}
	}
}
