/* Prior to Java2, a program used suspend(), resume() and stop(), which are
 * methods defined by the Thread, to pause, restart and stop the execution of a
 * thread. They are following:

   final void resume()
   final void suspend()
   final void stop()
*/

/* suspend() was deprecated by Java2, because it sometimes caused serious
 * problems that involve deadlock. The resume() is also deprecated not because
 * it caused any problem but because it can't be used without suspend() method
 * as its counterpart. The stop() method too sometimes caused problems so
 * deprecated by Java2 */

/* So, now a thread must be designed so that the run() method periodically
 * checks to determine if that thread should suspedn, resume or stop its own
 * execution. This is done by establishing two flag variables, one for suspend
 * and resume and other for stop. For suspend and resume as long as the flag is
 * set to "running", the run() method must continue to let the thread execute.
 * If this variable is set to "suspend", the thread must pause. For the stop,
 * if it is set to "stop", the thread must terminate */


// One way of suspending, resuming and stopping a thread

class MyThread implements Runnable {
	Thread thrd;
	boolean suspended;  // suspends thread when true
	boolean stopped;  // thread stops when true

	MyThread(String name) {
		this.thrd = new Thread(this, name);
		this.suspended = false;
		this.stopped = false;
	}

	// factory method
	public static MyThread createAndStart(String name) {
		MyThread mth = new MyThread(name);
		mth.thrd.start();
		return mth;
	}

	// Entry point of thread
	public void run() {
		System.out.println(this.thrd.getName() + " starting");
		try {
			for(int i = 0; i < 1000; ++i) {
				System.out.print(i + " ");
				if(i % 10 == 0) {
					System.out.println();
					Thread.sleep(250);  // this lets Main thread to execute(helps in context switching)
				}
				// Use synchronized block to check suspended and stopped
				synchronized(this) {
					while(this.suspended) {
						wait();
					}
					if(this.stopped) {
						break;
					}
				}
			}
		}
		catch(InterruptedException ie) {
			System.out.println(this.thrd.getName() + " interrupted");
		}
		// Program is not finishing right now, stops at 110 then "Suspending thread"
		System.out.println(this.thrd.getName() + " exiting");
	}

	// stop the thread
	synchronized void myStop() {
		System.out.println("myStop called");
		this.stopped = true;

		// the following ensures that a suspended thread can be stopped
		this.suspended = false;
		notify();
	}

	// suspend the thread
	synchronized void mySuspend() {
		System.out.println("mySuspend called");
		this.suspended = true;
	}

	// resume the thread
	synchronized void myResume() {
		System.out.println("myResume called");
		this.suspended = false;
		notify();
	}
}

public class Main {
	public static void main(String[] args) {
		MyThread mt1 = MyThread.createAndStart("My Thread");
		try {
			Thread.sleep(1000);  // let mt1 thread start executing

			// so now, when the mt1 thread is upto sleep for 250 sec 4th time,
			// that is the window for main thread to run below statements
			mt1.mySuspend();
			System.out.println("Suspending thread");
			Thread.sleep(1000);

			mt1.myResume();
			System.out.println("Resuming thread");
			Thread.sleep(1000);

			mt1.mySuspend();
			System.out.println("Suspending thread");
			Thread.sleep(1000);

			mt1.myResume();
			System.out.println("Resuming thread");
			Thread.sleep(1000);

			mt1.mySuspend();
			System.out.println("Suspending thread");
			Thread.sleep(1000);

			mt1.myResume();
			System.out.println("Resuming thread");
			Thread.sleep(1000);

			mt1.myStop();
			System.out.println("Stopped thread");
		}
		catch(InterruptedException ie) {
			System.out.println("Main thread interrupted");
		}

		// wait for thread to finish
		try {
			mt1.thrd.join();
		}
		catch(InterruptedException ie) {
			System.out.println("Main thread interrupted");
		}
		System.out.println("Main Thread exiting");
	}
}
