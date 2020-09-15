package bookpacker;

//import bookpack.*;
import bookpack.*;

//class BookDemo {
	//public static void main(String[] args) {
		//Book[] books = new Book[3];
		//books[0] = new Book("Java", "abc", 2019);
		//books[1] = new Book("Python", "xyz", 2020);
		//books[2] = new Book("C", "pqr", 2018);

		//for (int i = 0; i < books.length; ++i) {
			//books[i].show();
		//}
	//}
//}


class BookDemo {
	public static void main(String[] args) {
		bookpack.Book[] books = new bookpack.Book[3];
		books[0] = new bookpack.Book("Java", "abc", 2019);
		books[1] = new bookpack.Book("Python", "xyz", 2020);
		books[2] = new bookpack.Book("C", "pqr", 2018);

		for (int i = 0; i < books.length; ++i) {
			books[i].show();
		}
	}
}
