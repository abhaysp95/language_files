/** Use a BufferedReader to read characters from console */

import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

public class ReadChars {
	public static void main(String[] args) throws IOException {
		char c;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter characters, (.) to quit");
		do {
			c = (char) br.read();  // br is returning int
			System.out.print(c);
		} while(c != '.');  // quits after printing .
		br.close();  // free up
		System.out.println();
	}
}
