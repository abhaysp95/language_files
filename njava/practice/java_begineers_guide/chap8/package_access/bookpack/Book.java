// Demonstration of package in java

/* Three ways to use:
   1. If you package is in the subdirectory of the current directory it'll be found
   2. Specify directory path by setting up CLASSPATH env variable
   3. Using -classpath option with java and javac to specify path */

package bookpack;

public class Book {
	private String title;
	private String author;
	private int pubDate;

	public Book(String t, String a, int p) {
		this.title = t;
		this.author = a;
		this.pubDate = p;
	}

	public void show() {
		System.out.println(title);
		System.out.println(author);
		System.out.println(pubDate);
	}
}
