/* Main thread can be handled just like all other threads */

/* To access main thread, you must obtain a Thread object that refers to it. You od this by calling the currentThread() method, which is a static member of Thread.
   static Thread currentThread()
*/

public class UseMain {
	public static void main(String[] args) {
		Thread thrd;

		// Get the main thread
		thrd = Thread.currentThread();

		// Display the thread's name
		System.out.println("Main thread is called: " + thrd.getName());

		// display main thread's priority
		System.out.println("Main threads priority: " + thrd.getPriority());

		System.out.println();

		// set the name and priority
		System.out.println("Setting new name and priority");
		thrd.setName("New Main");
		thrd.setPriority(Thread.NORM_PRIORITY + 3);
		System.out.println("Main thread is now called: " + thrd.getName());
		System.out.println("Main threads new priority: " + thrd.getPriority());

		// you need to be careful on how you deal with main thread, example
		/*try {
			thrd.join();  // cause this will be waiting to main thread to finish
			// but the waiting one to finish is also main thread, so it's like
			// recursive way
		}
		catch (InterruptedException ie) {
			System.out.println("main thread interrupted");
		}*/
	}
}
