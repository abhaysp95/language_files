/* Key to synchronization is the concept of the monitor, which controls access
 * to an object. A monitor works by implementing the concept of lock. When an
 * object is locked by one thread, no other thread can gain access to the
 * object. When the thread exits, the object is unlocked and is available for
 * use by another thread */

/* All objects in java have a monitor. This feature is built into the java
 * language itself. Thus, all objects can be synchronized. Thus, all objects
 * can be synchronized and a few well-defined methods that all objects have */

/* There are two ways that you can synchronize your code */

// Using synchronized methods

/* You can modify a method by having synchronize as access with the
 * 'synchronized' keyword. When the method is called the calling thread enters
 * the object's monitor, which then locks the object. While locked, no other
 * thread can enter the method, or enter any other synchronized method defined
 * by the object's class. When the thread returns the method, the monitor
 * unlocks the object, allowing it to be used by the next thread. Thus,
 * synchronization is achieved with virtually no programming effort on your
 * part */


// The following program demonstrates synchronization by controlling access to
// a method

class SumArray {
	private int sum;

	// sumArray is now synchronized
	// try removing "synchronized" to see what effect does it make
	synchronized int sumArray(int[] nums) {
		sum = 0;  // reset sum
		for (int i = 0; i < nums.length; ++i) {
			sum += nums[i];
			System.out.println("Running total for " +
					Thread.currentThread().getName() +
					" is " + sum);
			try {
				System.out.println("sleeping " + Thread.currentThread().getName());
				Thread.sleep(10);  // allow task-switch
			}
			catch (InterruptedException ie) {
				System.out.println("Thread interrupted");
			}
		}
		return sum;
	}
}
/* Second child thread will not begin its execution until the first one is done
 * with it, a example of non-preemption */

class MyThread implements Runnable {
	Thread thrd;
	static SumArray sa = new SumArray();
	int a[];
	int answer;

	// construct a new thread
	MyThread(String name, int[] nums) {
		thrd = new Thread(this, name);
		this.a = nums;
	}

	// A factory method that creates and starts a thread
	public static MyThread createAndStart(String name, int[] nums) {
		MyThread myThrd = new MyThread(name, nums);
		myThrd.thrd.start();  // start the thread
		return myThrd;
	}

	// Entry point of thread
	public void run() {
		int sum;
		System.out.println(thrd.getName() + " starting");
		this.answer = this.sa.sumArray(a);
		System.out.println("Sum for " + this.thrd.getName() + " is " + this.answer);
		System.out.println(thrd.getName() + " terminating");
	}
}

class Sync {
	public static void main(String[] args) {
		int[] a = {1, 2, 3, 4, 5};
		MyThread mt1 = MyThread.createAndStart("Child #1", a);
		MyThread mt2 = MyThread.createAndStart("Child #2", a);
		try {
			mt1.thrd.join();
			mt2.thrd.join();
		}
		catch (InterruptedException ie) {
			System.out.println("Main thread interrupted");
		}
	}
}

/* For any given object, once a synchronized method has been called, the object
 * is locked and no synchronized methods on the same object can be used by
 * another thread of execution */
