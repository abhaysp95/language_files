/** the following programs declares a non-generic method and a static
 * generic method within that class */

class GenericMethodDemo {
	static <T extends Comparable<T>, V extends T> boolean arraysEqual(T[] x, V[] y) {
		if (x.length != y.length) { return false; }
		for (int i = 0; i < x.length; ++i) {
			if (!x[i].equals(y[i])) { return false; }
		}
		return true;
	}
}

public class Main {
	public static void main(String[] args) {
		Integer nums[] = { 1, 2, 3, 4, 5 };
		Integer nums2[] = { 1, 2, 3, 4, 5 };
		Integer nums3[] = { 1, 2, 7, 4, 5 };
		Integer nums4[] = { 1, 2, 7, 4, 5, 6 };

		if (GenericMethodDemo.arraysEqual(nums, nums)) {
			System.out.println("nums equal nums");
		}
		if (GenericMethodDemo.arraysEqual(nums, nums2)) {
			System.out.println("nums equal nums2");
		}
		if (GenericMethodDemo.arraysEqual(nums, nums3)) {
			System.out.println("nums equal nums3");
		}
		if (GenericMethodDemo.arraysEqual(nums, nums4)) {
			System.out.println("nums equal nums4");
		}
		/*Double dnums[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
		if (GenericMethodDemo.arraysEqual(nums, dnums)) {
			System.out.println("nums equal dnums");
		}*/
	}
}

/* Comparable is provided by java.lang. A class that implements Comparable defines objects that can be ordered. Thus, requiring an upper bound of Comparable ensures that arraysEqual() can be use
