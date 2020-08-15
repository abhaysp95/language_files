public class NumberOfDaysInMonth {
	public static boolean isLeapYear(int year) {
		boolean status = false;
		if (year >= 1 && year <= 9999) {
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
				status = true;
			}
		}
		return status;
	}

	public static int getDaysInMonth(int month, int year) {
		if ((month >= 1 && month <= 12) && (year >= 1 && year <= 9999)) {
			boolean ifLeapYear = isLeapYear(year);
			int numberOfDayS = 0;
			switch(month) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					numberOfDayS = 31;
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					numberOfDayS = 30;
					break;
				case 2:
					if (ifLeapYear) {
						numberOfDayS = 29;
					}
					else {
						numberOfDayS = 28;
					}
			}
			return numberOfDayS;
		}
		else {
			return -1;
		}
	}
}
