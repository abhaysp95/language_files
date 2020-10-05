/** Program to demonstrate multi-threading using Runnable interface(you can also extend Thread Class) */

package use_threads;

import java.lang.InterruptedException;

class MyThread implements Runnable {
	String threadName;

	MyThread(String name) {
		this.threadName = name;
	}

	// Entry point of thread
	public void run() {
		System.out.println("Thread: " + this.threadName + " starting");
		try {
			for (int count = 0; count < 10; ++count) {
				Thread.sleep(400);  // pauses the thread for 400 miliseconds
				System.out.println(this.threadName + ", count: " + count);
			}
		}
		catch (InterruptedException ie) {
			System.out.println(this.threadName + " is interrupted");
		}
		System.out.println(this.threadName + " terminating");
	}
}

public class UseThreads {
	public static void main(String[] args) {
		// First, construct a MyThread object
		MyThread mth = new MyThread("Child #1");  // create a runnable object
		// construct a thread from the object
		Thread newThread = new Thread(mth);
		// Start execution of the thread
		newThread.start();
		for (int i = 0; i < 50; ++i) {
			System.out.print(".");
			try {
				Thread.sleep(100);
			}
			catch (InterruptedException ie) {
				System.out.println("Main thread interrupted");
			}
		}
		System.out.println("Main thread finishing");
	}
}

/** In this example, it's using time difference(5s, 4s) of mth and main()
 * thread, becuase it is necessary to keep main() from terminating until mth is
 * finished, but this approach isn't good */
