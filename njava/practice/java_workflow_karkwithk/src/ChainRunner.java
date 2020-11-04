/** to run LinkedList */

public class ChainRunner<T> {
	public static void main(String[] args) {
		LinkList<String> strs = new LinkList<String>();
		strs.insert("Hello");
		strs.insert("World");
		System.out.println(strs);
	}
}
