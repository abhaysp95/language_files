/* you might want to synchronize access to some method that is not modified by
 * synchronized. This can occure because you want to use a class that was not
 * created by you and you don't have access to the source code. Thus, it is not
 * possible for you to add synchronized to appropriate methods within the
 * class. */

/* The general form of synchronized block:
   synchronized(objref) {
   // statements
   }
*/

// Same program as of synchronization_method but with synchronization block

class SumArray {
	private int sum;

	int sumArray(int[] arr) {
		this.sum = 0;
		for (int i = 0; i < arr.length; ++i) {
			sum += arr[i];
			System.out.println("Running total for " +
					Thread.currentThread().getName() +
					" is " + sum);
			try {
				Thread.sleep(10);
			}
			catch (InterruptedException ie) {
				System.out.println("Thread interrupted");
			}
		}
		return sum;
	}
}

class MyThread implements Runnable {
	Thread thrd;
	static SumArray sa = new SumArray();
	int a[];
	int answer;

	// construct a new Thread
	MyThread(String name, int[] arr) {
		this.thrd = new Thread(this, name);
		this.a = arr;
	}

	// factory method to create and start thread
	public static MyThread createAndStart(String name, int[] arr) {
		MyThread mth = new MyThread(name, arr);
		mth.thrd.start();
		return mth;
	}

	// Entry point of thread
	public void run() {
		int sum;
		System.out.println(thrd.getName() + " starting");
		// synchronize calls to sumArray
		synchronized(sa) {
			this.answer = this.sa.sumArray(this.a);
			// here calls to sumArray() on sa are synchronized
		}
		System.out.println("Sum for " + this.thrd.getName() + " is " + this.answer);
		System.out.println(this.thrd.getName() + " terminating");
	}
}

class Sync {
	public static void main(String[] args) {
		int a[] = {1, 2, 3, 4, 5};
		MyThread mt1 = MyThread.createAndStart("Child #1", a);
		MyThread mt2 = MyThread.createAndStart("Child #2", a);
		try {
			mt1.thrd.join();
			mt2.thrd.join();
		}
		catch(InterruptedException ie) {
			System.out.println("Main thread interrupted");
		}
	}
}
