// find if substring exist in main string

import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String mstring = scan.nextLine();
		String tstring = scan.nextLine();
		boolean found = false;

		try {
			for (int i = 0; i < mstring.length(); ++i) {
				if (i + tstring.length() > mstring.length()) {
					if (!found) {
						System.out.println("no");
					}
					break;
				}
				if (mstring.substring(i, i + tstring.length()).equals(tstring)) {
					System.out.println("Found substring at index: " + i);
					found = true;
					break;
				}
			}
		}
		catch (StringIndexOutOfBoundsException sie) {
			System.out.println("String indexing is not done properly " + sie);
			return;
		}
		finally {
			scan.close();
		}
	}
}
