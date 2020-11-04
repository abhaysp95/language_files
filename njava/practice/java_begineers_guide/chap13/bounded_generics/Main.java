class NumericsFns<T extends Number> {
	T num;

	NumericsFns(T n) {
		this.num = n;
	}

	// return the reciprocal
	double reciprocal() {
		return 1 / num.doubleValue();
		// since doubleValue() is available to all wrapper class, as
		// it's defined from Number Class
	}

	double fraction() {
		return num.doubleValue() - num.intValue();
	}

	/*boolean absEqual(NumericsFns<T> ob) {  // T is already of type Integer
		if (Math.abs(num.doubleValue()) ==
				Math.abs(ob.num.doubleValue())) {
			return true;
		}
		else {
			return false;
		}
	}*/

	boolean absEqual(NumericsFns<?> ob) {  // ? wildcard represents unknown type here
		// also, wildcar doesn't affect what type of NumericsFns
		// objects can be created, it is governed by the extends
		// clause in the NumericFns declaration
		if (Math.abs(num.doubleValue()) ==
				Math.abs(ob.num.doubleValue())) {
			return true;
		}
		else {
			return false;
		}
	}
}

public class Main {
	public static void main(String[] args) {
		NumericsFns<Double> ob = new NumericsFns<Double>(10.9);
		System.out.println(ob.reciprocal());
		System.out.println(ob.fraction());
		NumericsFns<Integer> ob1 = new NumericsFns<Integer>(14);
		System.out.println(ob1.reciprocal());
		System.out.println(ob1.fraction());
		//NumericsFns<String> ob1 = new NumericsFns<String>("Error");
		// this was the reason for bounded generics
		NumericsFns<Integer> ob2 = new NumericsFns<Integer>(-14);
		NumericsFns<Double> ob3 = new NumericsFns<Double>(14.0);
		NumericsFns<Long> ob4 = new NumericsFns<Long>(89L);
		System.out.println(ob2.absEqual(ob3));
		System.out.println(ob2.absEqual(ob4));
	}
}

/* Bounded types are espacially useful when you need to ensure that one type parameter is compatible with another.
   class Pair<T, V extends T> {
		T first;
		V second;
		Pair(T a, V b) {
			this.first = a;
			this.second = b;
		}
   }

   Here, Pair<Integer, Integer> x; is ok
   Pair<Number, Integer> x; is also ok
   Pair<Number, String> is not */
