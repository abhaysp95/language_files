/** Creation of thread by extending Thread */

package using_extended_thread;

class MyThread1 extends Thread {

	MyThread1(String name) {
		super(name);  // name thread
		// Thread(String name), super is used to call the Thread's constructor
	}

	public void run() {
		System.out.println(getName() + " starting");
		try {
			for (int i = 0; i < 10; ++i) {
				Thread.sleep(400);
				System.out.println("In " + getName() + ", count: " + i);
			}
		}
		catch (InterruptedException ie) {
			System.out.println(getName() + " interrupted");
		}
		System.out.println("Terminating " + getName());
	}
}



// class with variation and improvement(if needed)
class MyThread2 extends Thread {

	MyThread2(String name) {
		super(name);
	}

	// factory method
	public static MyThread2 createAndStart(String name) {
		MyThread2 mth2 = new MyThread2(name);
		mth2.start();
		return mth2;
	}

	public void run() {
		System.out.println(getName() + " starting");
		try {
			for (int i = 0; i < 10; ++i) {
				Thread.sleep(400);
				System.out.println("In " + getName() + ", count: " + i);
			}
		}
		catch (InterruptedException ie) {
			System.out.println(getName() + " interrupted");
		}
		System.out.println("Terminating " + getName());
	}
}

public class ExtendThread {
	public static void main(String[] args) {
		System.out.println("Main thread starting");
		MyThread1 mth = new MyThread1("Child #1");
		mth.start();  // because MyThread1 extends Thread, you can directly call start() with its instance unlike Runnable
		MyThread2.createAndStart("Child #2");
		/** It's generally good but not necessary to end the main thread at last */
		for (int i = 0; i < 10; ++i) {
			System.out.print(".");
			try {
				Thread.sleep(100);
			}
			catch (InterruptedException ie) {
				System.out.println("Main thread interrupted");
			}
		}
		System.out.println("Exiting main");
		return;
	}
}

/** Although, other methods of Thread class can also be overridden it is not
 * done generally */

/** So which approach is better, extending or implementing for threads ?*/
/** Some java programmers feel that classes should be extended only when they
 * are being expanded or customized in some way. So, if not overriding any of
 * Thread's methods(except run()), it's probably best to simply implement
 * Runnable. Also, by implementing Runnable, you enable your thread to inherit
 * a class other than Thread */
