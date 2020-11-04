public class LinkList<T> {
	private int size;
	private Node<T> head;
	private Node<T> tail;

	public LinkList() {
		this.size = 0;
	}

	private static class Node<T> {
		public T data;
		public Node<T> next;

		public Node(T data) {
			this.data = data;
		}

		public String toString() {
			return this.data.toString();
		}
	}

	public void insert(T data) {
		Node<T> newNode = new Node<T>(data);
		if (head == null) {
			head = newNode;
		}
		else {
			tail.next = newNode;
		}
		this.tail = newNode;
		this.size++;
	}

	public String toString() {
		String result = "";
		Node<T> current = head;
		while (current != null) {
			result += current + " ";
			current = current.next;
		}
		return result;
	}
}
