/* showing usage of constructors and methods in enum. Also, just like every
 * enum constant can access any method inside of the enum, each enum constant
 * has its own copy of field variables of that enum class */

enum Transport {
	CAR(56), TRUCK(55), AIRPLANE(600), TRAIN(70), BOAT(22);

	private int speed;  // typical speed for each transport

	Transport(int s) {
		this.speed = s;
	}

	int getSpeed() {
		return this.speed;
	}
}

public class EnumDemo3 {
	public static void main(String[] args) {
		Transport tp;

		System.out.println("Typical speed of airplane is: " +
				Transport.AIRPLANE.getSpeed() + " miles per hour");

		// display all transports and speed
		for (Transport t: Transport.values()) {
			System.out.println(t + " typical speed is: " +
					t.getSpeed() + " miles per hour");
		}

		System.out.println();

		EnumDemo4 obj1 = new EnumDemo4();
		obj1.twoInheritedMethods();
	}
}

/* so, this proves the fact enum constants are just just like of objects of that enum type */

/* Two limitations:
   1. an enumeration can't inherit another class
   2. an enum can't be a superclass
*/

/* All java enums automatically inherit one class: java.lang.Enum. There are two most occasionally used: oridinal() and compareTo()
   final int ordinal()
   final int compareTo(enum-type e)
*/

class EnumDemo4 {
	public void twoInheritedMethods() {
		Transport tp1, tp2, tp3;
		System.out.println("Here are all the transport constants and their ordinal values: ");
		for (Transport t: Transport.values()) {
			System.out.println(t + " " + t.ordinal());
		}
		tp1 = Transport.AIRPLANE;
		tp2 = Transport.TRAIN;
		tp3 = Transport.AIRPLANE;

		System.out.println();

		if (tp1.compareTo(tp2) < 0) {
			System.out.println(tp1 + " comes before " + tp2);
		}

		if (tp1.compareTo(tp2) > 0) {
			System.out.println(tp2 + " comes before " + tp1);
		}

		if (tp1.compareTo(tp3) == 0) {
			System.out.println(tp1 + " equals " + tp2);
		}
	}
}
