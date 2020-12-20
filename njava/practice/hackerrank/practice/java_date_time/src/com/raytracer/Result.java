package com.raytracer;

import java.util.Calendar;
import java.util.Date;
import java.util.Locale;
import java.time.LocalDate;

public class Result {
	public static String findDay(int month, int day, int year) {
		Calendar calendar = Calendar.getInstance();
		calendar.set(Calendar.MONTH, month - 1);
		calendar.set(Calendar.DAY_OF_MONTH, day);
		calendar.set(Calendar.YEAR, year);
		return calendar.getDisplayName(Calendar.DAY_OF_WEEK, Calendar.LONG, Locale.US).toUpperCase();
	}

	public static String findDayNew(int month, int day, int year) {
		LocalDate ld = LocalDate.of(year, month, day);
		return ld.getDayOfWeek().toString();
	}
}