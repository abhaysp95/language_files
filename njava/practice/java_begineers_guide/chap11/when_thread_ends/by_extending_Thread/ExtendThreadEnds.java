/** Determining when the thread ends */

package extended_thread_ends;

class MyThread extends Thread {
	MyThread(String name) {
		super(name);
	}

	/** Factory method */
	public static MyThread createAndStart(String name) {
		MyThread mth = new MyThread(name);
		mth.start();
		return mth;
	}

	public void run() {
		System.out.println("Starting: " + getName());
		try {
			for (int i = 0; i < 10; ++i) {
				Thread.sleep(400);
				System.out.println("In " + getName() + ", count: " + i);
			}
		}
		catch (InterruptedException ie) {
			System.out.println(getName() + " stopped unexpectedly");
		}
	}
}

public class ExtendThreadEnds {
	public static void main(String[] args) {
		System.out.println("Starting main: ");
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
		} while (mth1.isAlive() ||
				mth2.isAlive() ||
				mth3.isAlive());
		/** This will wait until all threads terminate */
		System.out.println("Main thread ending");
	}
}
