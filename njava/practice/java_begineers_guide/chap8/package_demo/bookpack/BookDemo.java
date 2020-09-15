// Demonstration of package in java

/* Three ways to use:
   1. If you package is in the subdirectory of the current directory it'll be found
   2. Specify directory path by setting up CLASSPATH env variable
   3. Using -classpath option with java and javac to specify path */

package bookpack;

class Book {
	private String title;
	private String author;
	private int pubDate;

	Book(String t, String a, int p) {
		this.title = t;
		this.author = a;
		this.pubDate = p;
	}

	void show() {
		System.out.println(title);
		System.out.println(author);
		System.out.println(pubDate);
	}
}

class BookDemo {
	public static void main(String[] args) {
		Book[] books = new Book[3];
		books[0] = new Book("Java", "abc", 2019);
		books[1] = new Book("Python", "xyz", 2020);
		books[2] = new Book("C", "pqr", 2018);

		for (int i = 0; i < books.length; ++i) {
			books[i].show();
		}
	}
}
