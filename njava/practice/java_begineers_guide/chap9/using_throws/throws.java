package using_throws;

import java.io.IOException;

/* In some cases, if a method generates an exception that it does not handle,
 * it must declare that exception in "throws" clause */


/* general syntax
   ret-type methodName(param-list) throws <except-list> {
   // body
   }
*/

/* Exceptions that are subclasses of Error or RuntimeException don't need to
 * be specified in a "throws" list. Java simply assumes that a method may
 * throw one */

class ThrowsDemo {
	public static char prompt (String str)
		throws IOException {  // <-- throws block
		System.out.println(str + ": ");
		return (char) System.in.read();
	}

	public static void main(String[] args) {
		char ch;
		// since prompt() might throw an exception, a call to it must be
		// enclosed with a try block
		try {
			ch = prompt("Enter a letter");
		}
		catch (IOException jii) {
			System.out.println("I/O Exception occured");
			ch = 'X';
		}
		System.out.println("You pressed: " + ch);
	}
}
