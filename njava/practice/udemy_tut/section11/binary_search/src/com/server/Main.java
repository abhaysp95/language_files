package com.server;

public class Main {
	public static void main(String[] args) {
		Theatre theatre = new Theatre("Olympian", 8, 15);
		theatre.getSeats();

		if (theatre.reserveSeat("H04")) {
			System.out.println("Please Pay");
		}
		else {
			System.out.println("Sorry, seat is taken");
		}

		/** this time the seat is taken */
		if (theatre.reserveSeat("H04")) {
			System.out.println("Please Pay");
		}
		else {
			System.out.println("Sorry, seat is taken");
		}

		if (theatre.reserveSeat("D08")) {
			System.out.println("Please Pay");
		}
		else {
			System.out.println("Sorry, seat is taken");
		}
	}
}
