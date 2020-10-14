// Autoboxing/unboxing takes place with method parameters and return values

public class AutoBox {
	// method has an Integer parameter
	static void m(Integer v) {
		System.out.println("m() recieved " + v);
	}

	// method returns an int
	static int m2() {
		return 10;
	}

	// method returns an Integer
	static Integer m3() {
		return 99;  // autoboxing 99 into an Integer
	}

	public static void main(String[] args) {
		m(199);  // autoboxing on parameter
		Integer iOb = m2();  // autoboxing
		System.out.println("Return value from m2() is " + iOb);
		int i = m3();  // auto-unboxing
		System.out.println("Return value from m3() is " + i);
		iOb = 100;
		System.out.println("Square root of iOb is " + Math.sqrt(iOb));

		/* In general, autoboxing and unboxing takes place whenever a
		 * conversion into an object or from an object is required. */

		++iOb;
		System.out.println("After ++iOb: " + iOb);
		// automatically unboxes and performes Increment and then reboxes, so
		// it's same as below
		Integer iOb2 = 100;
		i = iOb2.intValue();
		iOb2 = Integer.valueOf(++i);
		System.out.println("After ++iOb2: " + iOb2);

		iOb2 = iOb + (iOb / 3);
		System.out.println("iOb2 after expression: " + iOb2);
		// the above is same as
		iOb2 = Integer.valueOf(iOb.intValue() + (iOb.intValue() / 3));

		i = iOb + (iOb / 3);
		// the same expression is evaluated, but the result is not reboxed
		System.out.println("i after expression: " + i);
	}
}

/* you should restrict your use of the type wrappers to only those cases in
 * which an object representation of a primitive type is required */
