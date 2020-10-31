package com.server;

import java.util.*;

public class Theatre {
	private final String theatreName;
	private List<Seat> seats = new ArrayList<Seat>();
	//private Collection<Seat> seats = new LinkedList<Seat>();
	//private Collection<Seat> seats = new HashSet<Seat>();
	//private Collection<Seat> seats = new LinkedHashSet<Seat>();
	//private Collection<Seat> seats = new TreeSet<Seat>();

	Theatre(String name, int numRows, int seatsPerRow) {
		this.theatreName = name;
		int lastRow = 'A' + (numRows - 1);
		for (char row = 'A'; row <= lastRow; ++row) {
			for (int seatNum = 1; seatNum <= seatsPerRow; ++seatNum) {
				Seat seat = new Seat(row + String.format("%02d", seatNum));
				seats.add(seat);
			}
		}
	}

	public String getTheatreName() { return this.theatreName; }

	/** Working, alternate binarySearch code from java source code below */
	/*public boolean reserveSeat(String seatNumber) {
		Seat requestedSeat = new Seat(seatNumber);
		int foundSeat = Collections.binarySearch(seats, requestedSeat, null);
		if (foundSeat >= 0) {
			return seats.get(foundSeat).reserve();
		}
		else {
			System.out.println("There's no seat: " + seatNumber);
			return false;
		}
		[>for (Seat seat: seats) {
			System.out.println(".");
			if (seat.getSeatNumber().equals(seatNumber)) {
				requestedSeat = seat;
				break;
			}
		}
		if (requestedSeat == null) {
			System.out.println("There's no seat with this name");
			return false;
		}
		return requestedSeat.reserve();<]
	}*/

	public boolean reserveSeat(String seatNumber) {
		int low = 0;
		int high = seats.size() - 1;
		Seat requestedSeat = new Seat(seatNumber);

		while (low <= high) {
			System.out.println('.');  // took 5 dots
			int mid = ((low + high) / 2);
			Seat midVal = seats.get(mid);
			//int cmp = midVal.getSeatNumber().compareTo(seatNumber);
			int cmp = midVal.compareTo(requestedSeat);  // this is using overriden compareTo method from Seat class
			if (cmp < 0) {
				low = mid + 1;
			}
			else if (cmp > 0) {
				high = mid - 1;
			}
			else {
				return seats.get(mid).reserve();
			}
		}
		System.out.println("There's no seat: " + seatNumber);
		return false;
	}

	public void getSeats() {
		for (Seat seat: seats) {
			System.out.println(seat.getSeatNumber());
		}
	}

	private class Seat implements Comparable<Seat> {
		private final String seatNumber;
		private boolean reserved = false;

		public Seat(String seatNumber) {
			this.seatNumber = seatNumber;
		}

		@Override
		public int compareTo(Seat seat) {
			return this.seatNumber.compareToIgnoreCase(seat.getSeatNumber());
		}

		public boolean reserve() {
			if (!this.reserved) {
				this.reserved = true;
				System.out.println("Seat " + seatNumber + " now reserved");
				return true;
			}
			else { return false; }
		}

		public boolean cancel() {
			if (this.reserved) {
				this.reserved = false;
				System.out.println("Reservation of seat " + seatNumber + " cancelled");
				return true;
			}
			else { return false; }
		}

		public String getSeatNumber() { return this.seatNumber; }
	}
}

/** Collection is implemented by set, list, queue, deque */
