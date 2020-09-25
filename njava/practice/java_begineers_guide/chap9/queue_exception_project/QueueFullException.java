package queue_exception;

public class QueueFullException extends Exception {
	int size;

	QueueFullException(int size) {
		this.size = size;
	}

	@Override
	public String toString() {
		return "\nFrom Exception: Queue is full. Max. size is: " + this.size;
	}
}
