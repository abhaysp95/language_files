/** same program to check if threads are alive but with runnable interface */

package when_thread_ends;

class MyThread implements Runnable {
	Thread thrd;  // cause this thread instance is used outside of this class,
	// so it can't be private

	MyThread(String name) {
		thrd = new Thread(this, name);
	}

	public static MyThread createAndStart(String name) {
		MyThread mth = new MyThread(name);
		mth.thrd.start();
		return mth;
	}

	public void run() {
		System.out.println("Starting " + this.thrd.getName());
		try {
			for (int i = 0; i < 10; ++i) {
				Thread.sleep(400);
				System.out.println("In " + this.thrd.getName() +
						", count: " + i);
			}
		}
		catch (InterruptedException ie) {
			System.out.println(this.thrd.getName() + " interrupted unexpectedly");
		}
	}
}

public class WhenThreadsEnd {
	public static void main(String[] args) {
		System.out.println("Starting Main thread");
		MyThread mth1 = MyThread.createAndStart("Child #1");
		MyThread mth2 = MyThread.createAndStart("Child #2");
		MyThread mth3 = MyThread.createAndStart("Child #3");

		do {
			System.out.print(".");
			try {
				Thread.sleep(100);
			}
			catch (InterruptedException ie) {
				System.out.println("Main thread stopped unexpectedly");
			}
		} while (mth1.thrd.isAlive() ||
				mth2.thrd.isAlive() ||
				mth3.thrd.isAlive());
		System.out.println("Main thread ends");
	}
}
