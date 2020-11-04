import com.server.*;

public class Main {
	public static void main(String[] args) {
		Array<Integer> arr = new Array<Integer>(10);
		for (int i = 0; i < 10; ++i) {
			arr.add(i + 1);
		}
		System.out.println(arr.toString());
		arr.removeAt(12);
		System.out.println(arr.toString());
		arr.remove(16);  /** This here is problem(not working), NullPointerException */
		System.out.println(arr.toString());
	}
}
