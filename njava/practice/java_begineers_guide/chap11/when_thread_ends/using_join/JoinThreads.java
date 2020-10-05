/** Using join */

class MyThread implements Runnable {
	Thread thrd;

	MyThread(String name) {
		thrd = new Thread(this, name);
	}

	public static MyThread craeteAndStart(String name) {
		MyThread mth = new MyThread(name);
		mth.thrd.start();
		return mth;
	}

	// Entry point of thread
	public void run() {
		System.out.println(thrd.getName() + " starting");
		try {
			for (int i = 0; i < 10; ++i) {
				Thread.sleep(400);
				System.out.println("In " + thrd.getName() + ", count: " + i);
			}
		}
		catch (InterruptedException ie) {
			System.out.println(thrd.getName() + " interrupted");
		}
		System.out.println(thrd.getName() + " terminating");
	}
}

public class JoinThreads {
	public static void main(String[] args) {
		System.out.println("Starting main");
		MyThread mt1 = MyThread.craeteAndStart("Child #1");
		MyThread mt2 = MyThread.craeteAndStart("Child #2");
		MyThread mt3 = MyThread.craeteAndStart("Child #3");

		try {
			mt1.thrd.join();
			System.out.println(mt1.thrd.getName() + " joined");
			mt2.thrd.join();
			System.out.println(mt2.thrd.getName() + " joined");
			mt3.thrd.join();
			System.out.println(mt3.thrd.getName() + " joined");
		}
		catch (InterruptedException ie) {
			System.out.println("Main thread interrupted");
		}
		System.out.println("Main thread ending");
	}
}

/** The method with join waits until the thread on which it is called
 * terminates. Its name comes from the concept of the calling thread waiting
 * until the specified thread joins it. Additional forms of join() allow you to
 * specify maximum amount of time that you want to wait for the specified
 * thread to terminate */
