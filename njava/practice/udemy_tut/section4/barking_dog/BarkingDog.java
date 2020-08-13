public class BarkingDog {
	public static boolean shouldWakeUp(boolean barking, int hourOfDay) {
		if (hourOfDay < 0 || hourOfDay > 23) {
			return false;
		}
		else {
			if (!barking) {
				System.out.println("Dog is not barking");
			}
			else if (hourOfDay < 8 || hourOfDay > 22) {
				return true;
			}
		}
		return false;
	}
}
