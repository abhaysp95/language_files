/* A bounded wildcard is espacially important when you are creating a method
 * that is designed to operate only on objects that are subclass of a specific
 * superclass */


/** first part */

class A {}

class B extends A {}

class C extends A {}

class D {}

class Gen<T> {
	// if we extend T to A here, then D can't be created
	T ob;

	Gen(T o) { this.ob = o; }
}

/** ***************** */






/** second part */

class Gen2<T extends ParentItIs> {
	T ob;

	Gen2(T o) {
		this.ob = o;
	}

	/*void test(Gen2<? extends T> o) {
		System.out.println(o);
	}*/
	// above will not working because Gen2 is of type T and I'm changing the
	// type of Gen2 in the above method's parameter

	<T2 extends T> void test(T2 o) {
		System.out.println(o.getClass().getName());
	}
}

class ParentItIs {}

class ChildItIs extends ParentItIs {}

class GrandChildItIs extends ChildItIs {}


/** ***************** */

public class Main {
	private static void test(Gen<? extends A> o) {}

	public static void main(String[] args) {
		/** first part */
		A a = new A();
		B b = new B();
		C c = new C();
		D d = new D();

		Gen<A> w1 = new Gen<A>(a);
		Gen<B> w2 = new Gen<B>(b);
		Gen<C> w3 = new Gen<C>(c);
		Gen<D> w4 = new Gen<D>(d);

		// These calls to test() are ok
		test(w1);
		test(w2);
		test(w3);

		// can't call test() with w4 because it is not an object of a
		// class that inherits A
		//test(w4);

		/** ***************** */


		/** second part */

		ParentItIs p = new ParentItIs();
		ChildItIs c1 = new ChildItIs();
		GrandChildItIs g = new GrandChildItIs();
		Gen2<ChildItIs> w5 = new Gen2<ChildItIs>(c1);  // you have to pass 'c', not 'p' as Type of T is ChildItIs
		w5.test(g);

		/** ***************** */
	}
}

/* The above <? extends superclass> is an inclusive clause and you can also
 * have a exclusive clause with <? super subclass>, maybe that's helpful where
 * subclass is a class and ? is all the Interface which is extended by that
 * clause, since java doesn't support multiple inheritance of class, that's the
 * only usecase I can think of */
