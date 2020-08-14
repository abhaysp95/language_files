public class TeenNumberChecker {
	public static boolean hasTeen(int teen1, int teen2, int teen3) {
		boolean result = false;
		if (isTeen(teen1) || isTeen(teen2) || isTeen(teen3)) {
			result = true;
		}
		return result;
	}
	public static boolean isTeen(int teen) {
		if (teen >= 13 && teen <= 19) {
			return true;
		}
		return false;
	}
}
