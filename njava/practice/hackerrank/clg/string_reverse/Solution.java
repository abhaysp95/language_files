import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class StringReverse {
	static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
	public void isPalindrome() {
		try {
			StringBuilder sb = new StringBuilder(bf.readLine());
			String s = sb.toString();
			if (s.equals(sb.reverse().toString())) {
				System.out.println("Yes");
			}
			else {
				System.out.println("No");
			}
		}
		catch (IOException ie) {
			System.out.println("Some IOException: " + ie);
		}
	}
}

class StringReverseTraditional {
	public void isPalindrome() {
		try {
			StringBuilder sb = new StringBuilder(StringReverse.bf.readLine());
			char c;
			for (int i = 0; i < sb.length() / 2; ++i) {
				spi = sb.length() - i - 1;
				c = sb.charAt(spi);
				//sb.deleteCharAt(sb.length() - i - 1);
				//sb.append(sb.charAt(i));
				//sb.insert(sb.length() - i - 1, sb.charAt(i));
				sb.replace(sb.length())
				sb.replace(i, i + 1, ((Character)c).toString());
			}
			System.out.println(sb);
		}
		catch (IOException ie) {
			System.out.println("Some IOException: " + ie);
		}
	}
}

public class Solution {
	public static void main(String[] args) {
		StringReverse ob = new StringReverse();
		ob.isPalindrome();
		StringReverseTraditional ob2 = new StringReverseTraditional();
		ob2.isPalindrome();
	}
}
