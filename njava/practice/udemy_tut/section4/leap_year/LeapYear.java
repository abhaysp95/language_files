public class LeapYear {
	public static boolean isLeapYear(int year) {
		boolean gotLeapYear = false;
		if (year >= 1 && year <= 9999) {
			if (year % 4 == 0) {
				if (year % 100 == 0) {
					if (year % 400 == 0) {
						gotLeapYear = true;
					}
				}
				else {
					gotLeapYear = true;
				}
			}
		}
	return gotLeapYear;
	}
}
