// get the time

public class Main {

	// final keyword is making this variable behave as constant
	public static final String INVALID_VALUE_MESSAGE = "Invalid Value Passed As Parameter";

	public static void main(String args[]) {
		String got_time = getDurationString(63, 34);
		System.out.println(got_time);
		String got_one_more_time = getDurationString(65, 9);
		System.out.println(got_one_more_time);
		String another_time = getDurationString(1863);
		System.out.println(another_time);
	}

	public static String getDurationString(int minutes, int seconds) {
		if (minutes < 0 || (seconds < 0 || seconds > 59)) {
			return INVALID_VALUE_MESSAGE;
		}
		else {
			int got_hours = minutes / 60;
			int got_minutes = minutes % 60;
			int got_seconds = seconds;
			//String new_got_hours = printNice("" + got_hours);
			//String new_got_minutes = printNice("" + got_minutes);
			//String new_got_seconds = printNice("" + got_seconds);
			//return new_got_hours + "h " + new_got_minutes + "m " + new_got_seconds + "s";
			return printNice(got_hours) + "h " + printNice(got_minutes) + "m " + printNice(got_seconds) + "s";
		}
	}

	public static String getDurationString(int seconds) {
		if (seconds < 0) {
			return INVALID_VALUE_MESSAGE;
		}
		else {
			int got_minutes = seconds / 60;
			int got_seconds = seconds % 60 ;
			return getDurationString(got_minutes, got_seconds);
		}
	}

	public static String printNice(String time) {
		if (time.length() == 1) {
			return "0" + time;
		}
		else {
			return time;
		}
	}

	public static String printNice(int time) {
		if (time >= 0 && time <= 9) {
			return "0" + time;
		}
		else {
			return "" + time;
		}
	}
}
