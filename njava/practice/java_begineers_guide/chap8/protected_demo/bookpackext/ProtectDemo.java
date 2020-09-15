package bookpackext;

class ExtBook extends bookpack.Book {
	private String publisher;

	public ExtBook (String t, String a, int d, String p) {
		super(t, a, d);
		this.publisher = p;
	}

	public void show() {
		super.show();
		System.out.println(publisher);
		System.out.println();
	}

	public String getPublisher() { return this.publisher; }
	public void setPublisher(String p) { this.publisher = p; }

	/* These are OK because subclass can access a protected member */
	public String getTitle() { return title; }  // you know what'll happen if wrote this.title or super.title or just title
	public String getAuthor() { return author; }
	public int getPubDate() { return pubDate; }
	public void setTitle(String t) { title = t; }
	public void setAuthor(String a) { author = a; }
	public void setPubDate(int d) { pubDate = d; }
}

class ProtectDemo {
	public static void main(String[] args) {
		ExtBook books[] = new ExtBook[3];
		books[0] = new ExtBook("Java", "abc", 2019, "cde");
		books[1] = new ExtBook("Python", "xyz", 2020, "gef");
		books[2] = new ExtBook("C", "abc", 2018, "rst");

		System.out.println("Showing all books by abc:");
		for (int i = 0; i < books.length; ++i) {
			if (books[i].getAuthor().equals("abc")) {
				System.out.println(books[i].getTitle());
			}
		}
		//books[0].title = "test title"; // access to protected field not allowed by non-subclass
	}
}
