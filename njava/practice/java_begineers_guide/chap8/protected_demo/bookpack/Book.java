package bookpack;

public class Book {
	protected String title;
	protected String author;
	protected int pubDate;

	public Book(String t, String a, int d) {
		this.title = t;
		this.author = a;
		this.pubDate = d;
	}

	public void show() {
		System.out.println(title);
		System.out.println(author);
		System.out.println(pubDate);
		System.out.println();
	}
}
