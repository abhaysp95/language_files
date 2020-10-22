import java.io.BufferedReader;
import java.io.InputStreamReader;

class Count {
	static int getCount(int num) {
		if (num <= 1) {
			return 1;
		}
		return 1 + Count.getCount(num / 10);
	}
}

public class Solution {
	public static void main(String[] args) {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		try {
			int num = Integer.parseInt(bf.readLine());
			if (num <= 0 || num >= Integer.MAX_VALUE) {
				System.out.println("out of range");
			}
			else {
				System.out.println("Count is: " + Count.getCount(num));
			}
		}
		catch (Exception e) {
			System.out.println("Some IOException");
		}
	}
}
