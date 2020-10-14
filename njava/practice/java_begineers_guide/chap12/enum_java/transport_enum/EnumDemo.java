// enumerations are useful whenever you need to define a set of values that represent a collection of items, eg., status codes etc., in the past such values were defined by final variables

// An enumeration of Transport varieties

// enum is just "static final int[] SwitchMap*"
enum Transport {
	CAR, TRUCK, AIRPLANE, TRAIN, BOAT
}

class EnumDemo {
	public static void main(String[] args) {
		Transport tp;

		tp = Transport.AIRPLANE;

		// output of enum value
		System.out.println("Value of tp: " + tp);
		System.out.println();

		tp = Transport.TRAIN;

		// compare two enum values
		if (tp == Transport.TRAIN) {
			System.out.println("tp contains TRAIN");
		}

		// use enum to control a switch statement
		switch (tp) {
			case CAR:
				System.out.println("A car carries people");
				break;
			case TRUCK:
				System.out.println("A truck carries frieght");
				break;
			case AIRPLANE:
				System.out.println("An aiplane flies");
				break;
			case TRAIN:
				System.out.println("A train runs on rail");
				break;
			case BOAT:
				System.out.println("A boat sails on water");
				break;
		}

		System.out.println("-------------------------------");

		// demo2
		EnumDemo2 obj2 = new EnumDemo2();
		obj2.demo();
	}
}

/* java implements enumerations as class types, although you instantiate enum using new, it otherwise acts much like other classes, you can give it constructors, add instace variables and methods, and even implement interfaces. */

/* All enumerations have two pre-defined methods:
   public static enum-type[] values()
   public static enum-type valueOf(String str)
*/

class EnumDemo2 {
	public void demo() {
		Transport tp;
		System.out.println("Here are all transport constants");

		// use values()
		Transport allTransportes[] = Transport.values();
		for (Transport t: allTransportes) {
			System.out.println(t);
		}
		System.out.println();

		// use valueOf
		tp = Transport.valueOf("AIRPLANE");
		System.out.println("tp contains: " + tp);
	}
}
