/** MyThread Varaitions. This version of MyThread creates when its constructor
 * is called and stores it in an instance variable called thrd. It also sets
 * the name of the thread and provides a factory method to create and start a
 * thread */

package use_threads;

class MyThread implements Runnable {
	private Thread thrd;

	// Construct a new thread using this Runnable and give it a name
	MyThread (String name) {
		thrd = new Thread(this, name);
	}
	// Now, thread is ready to start as soon as constructor returns, You simply
	// call start() on Thread instance(thrd) encapsulated by MyThread

	// A factory method that creates and starts a thread
	public static MyThread createAndStart(String name) {
		MyThread myThrd = new MyThread(name);
		myThrd.thrd.start();  // start the thread
		return myThrd;  // maybe returning this because if want to handle the thread from outside
	}
	// Advantage of above static factory method is that, thread begins
	// execution as soon as it is created. This approach is useful when there's
	// no need to seperate thread creation from thread execution

	public void run() {
		// There's also Thread.setName() to set the name of thread after
		/** final void setName(String threadName) */
		System.out.println(thrd.getName() + " starting.");
		try {
			for (int i = 0; i < 10; ++i) {
				Thread.sleep(400);
				System.out.println("In " + thrd.getName() +
						", count: " + i);
			}
		}
		catch (InterruptedException ie) {
			System.out.println(thrd.getName() + " interrupted.");
		}
		System.out.println(thrd.getName() + " terminating.");
	}
}

public class ImprovedUseThreads {
	public static void main(String[] args) {
		System.out.println("Main thread starting");
		// Now thread starts as soon as it's created and begins execution
		MyThread mt = MyThread.createAndStart("Child #1");
		//MyThread.createAndStart("Child #1");
		for (int i = 0; i < 50; ++i) {
			System.out.print(".");
			try {
					Thread.sleep(100);
			}
			catch (InterruptedException ie) {
				System.out.println("Main thread interrupted");
			}
		}
	}
}

/** Unless you want to have thread's execution seperate from its creation, this improvement is going to be pretty useful */

/** Factory Method: A factory method is a method that returns an object of a
 * class. Typically, factory methods are static methods of a class. Factory
 * methods are useful in many situations. In some cases, it's also possible for
 * a factory method to reuse an object, rather than constructing a new one */
