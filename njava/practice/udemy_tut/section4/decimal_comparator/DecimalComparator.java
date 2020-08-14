public class DecimalComparator {
	public static boolean areEqualByThreeDecimalPlaces(double num1, double num2) {
		double onlyDecimalValue1 = num1 % (int)num1;
		double onlyDecimalValue2 = num2 % (int)num2;
		int changedToInt1 = (int)(num1 * 1000);
		int changedToInt2 = (int)(num2 * 1000);
		if (changedToInt1 == changedToInt2) {
			return true;
		}
		return false;
	}
}
