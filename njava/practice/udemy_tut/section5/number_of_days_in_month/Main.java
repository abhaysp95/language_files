public class Main {
	public static void main(String args[]) {
		boolean status1 = NumberOfDaysInMonth.isLeapYear(1700);
		boolean status2 = NumberOfDaysInMonth.isLeapYear(1600);
		boolean status3 = NumberOfDaysInMonth.isLeapYear(2020);
		print_statement(status1);
		print_statement(status2);
		print_statement(status3);

		System.out.println("------------------------------------");

		int daysInMonthYear1 = NumberOfDaysInMonth.getDaysInMonth(1, 2020);
		int daysInMonthYear2 = NumberOfDaysInMonth.getDaysInMonth(2, 2020);
		int daysInMonthYear3 = NumberOfDaysInMonth.getDaysInMonth(2, 2018);
		int daysInMonthYear4 = NumberOfDaysInMonth.getDaysInMonth(-1, 2020);
		int daysInMonthYear5 = NumberOfDaysInMonth.getDaysInMonth(1, -2020);
		System.out.println("Number of days: " + daysInMonthYear1);
		System.out.println("Number of days: " + daysInMonthYear2);
		System.out.println("Number of days: " + daysInMonthYear3);
		System.out.println("Number of days: " + daysInMonthYear4);
		System.out.println("Number of days: " + daysInMonthYear5);
	}

	public static void print_statement(boolean status) {
		if (status) {
			System.out.println("Given year is leap year");
		}
		else {
			System.out.println("Given year is not leap year");
		}
	}
}
