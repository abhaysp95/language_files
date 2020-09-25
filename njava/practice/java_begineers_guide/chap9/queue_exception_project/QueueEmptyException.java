package queue_exception;

public class QueueEmptyException extends Exception {

	@Override
	public String toString() {
		return "\nFrom exception: Queue is Empty";
	}
}
