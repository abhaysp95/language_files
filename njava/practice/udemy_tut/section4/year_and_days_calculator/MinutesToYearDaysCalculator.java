public class MinutesToYearDaysCalculator {
	public static void printYearsAndDays(long minutes) {
		if (minutes < 0) {
			System.out.println("Invalid Value");
		}
		else {
			System.out.print(minutes + " min = " + (minutes / (60 * 24 * 365)) + " y and ");
			long remaining_days = minutes % (365 * 60 * 24);
			remaining_days /= (60 * 24);
			System.out.println(remaining_days + " d");
		}
	}
}
