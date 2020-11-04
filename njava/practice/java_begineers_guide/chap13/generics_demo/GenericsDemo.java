// A simple generic class

/* here, T is a type parameter that will be replaced by a real type when an
 * object of type Gen is created */

class Gen<T> {
	T ob;  // declare an object of type T
	// declare a generic class, T is the generic type parameter

	// pass the constructor a reference to an object of type T
	Gen(T o) {
		this.ob = o;
	}

	// Return ob
	T getOb() {
		return this.ob;
	}

	// show type of T
	void showType() {
		System.out.println("Type of T is: " + ob.getClass().getName());
	}
}

class Gen2<T, V> {
	T ob1;
	V ob2;

	Gen2(T o1, V o2) {
		this.ob1 = o1;
		this.ob2 = o2;
	}

	T getOb1() {
		return this.ob1;
	}

	V getOb2() {
		return this.ob2;
	}

	void showTypes() {
		System.out.println("Type of T is: " + this.ob1.getClass().getName() +
				", Type of V is: " + this.ob2.getClass().getName());
	}
}

// Demonstrate the generic class
class GenDemo {
	public static void main(String[] args) {
		Gen<Integer> iOb;
		Gen<Integer> iOb2;

		// Create a Gen<Integer> object and assign its reference to iOb.
		// Notice the use of autoboxing to encapsulate the value of 88
		// withing an Integer object
		iOb = new Gen<Integer>(88);  // autoboxing
		iOb2 = new Gen<Integer>(Integer.valueOf(88));  // manual boxing

		// show type of data used by iOb
		iOb.showType();
		iOb2.showType();

		// get the value of  iOb
		int u = iOb.getOb();
		int v = iOb2.getOb();
		System.out.println("u: " + u + ", v: " + v);
		System.out.println();

		// Create a Gen object for Strings
		Gen<String> strOb = new Gen<String>("Generics Text");
		strOb.showType();
		String str = strOb.getOb();
		System.out.println("value: " + str);
		System.out.println();

		Gen2<Integer, String> ob2 = new Gen2<Integer, String>(88, "Generics");
		ob2.showTypes();
		int x = ob2.getOb1();
		String s = ob2.getOb2();
		System.out.println("value: " + x + ", value: " + s);
	}
}

/* also begining with JDK10, you can't use var as type parameter */

/* line:
 * T ob;  // declare an object of type T
 *
 * T is placeholder for the actual type that will be specified when a Gen
 * object is created. Thus, ob will be an object of the type passed to T.
 * Example, is String is passed to T, then in that instance, ob will be type
 * String */

/* regarding showType()
 * Object class defines getClass(). It returns a Class object that
 * corresponds to the class type of the object on which it is called. Class
 * is a class defined within java.lang that encapsulates information about a
 * class. Among these getName() method, which returns a string representation
 * of the class name */

/* Note:
 * iOb = strOb;  // Wrong, error: incompatible types
 * Even though both iOb and strOb are of type Gen<T>, they are references to
 * different types because their type arguments differ. This is part of the
 * way that generics add type safety and prevent errors. */

/* full syntax for declaring a reference to a generic class and creating a
 * generic instance:
   class-name<type-param-list> var-name =
                            new class-name<type-arg-list>(cons-arg-list)
 */
