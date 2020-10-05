/** few threading basics */

/** when a child thread is started, its priority setting is equal  to that of its parent thread. You can change a thread's priority by calling setPriority(), which is a member of Thread. This is general form:
final void setPriority(int level) */

/** The value of level must be between MIN_PRIORITY and MAX_PRIORITY, currently these values are 1 and 10, respectively */
// So java makes it opposite of what I have used in linux is that it gives higher priority to higher number, while linux(some utility name can't remember) gives higher priority to lower number

/** To return a thread to default priority, specify NORM_PRIORITY, which is currently 5 */

/** You can obtain the current priority setting by calling the getPriority() method of Thread:
final int getPriority() */

/** The threads are created as instances of Priority. The run() method contains a loop that counts the number of iterations */


// Demonstrate thread priorities

class Priority implements Runnable {
	int count;
	Thread thrd;

	static boolean stop = false;
	static String currentName;

	// construct a new thread
	Priority(String name) {
		this.thrd = new Thread(this, name);
		this.count = 0;
		this.currentName = name;
	}

	// Entry point of thread
	public void run() {
		System.out.println(this.thrd.getName() + " starting");
		do {
			count++;
			if (this.currentName.compareTo(this.thrd.getName()) != 0) {
				this.currentName = this.thrd.getName();
				//System.out.println("In " + this.currentName);
			}
		} while (this.stop != true && count < 10000000);
		this.stop = true;
		//System.out.println("\n" + this.thrd.getName() + " terminating.");
	}
}


public class BasicThreading {
	public static void main(String[] args) {
		Priority p1 = new Priority("High Priority");
		Priority p2 = new Priority("Low Priority");
		Priority p3 = new Priority("Normal Priority #1");
		Priority p4 = new Priority("Normal Priority #2");
		Priority p5 = new Priority("Normal Priority #3");
		Priority p6 = new Priority("Normal Priority #4");

		p1.thrd.setPriority(Thread.NORM_PRIORITY + 4);
		p2.thrd.setPriority(Thread.NORM_PRIORITY - 4);
		// rest of the threads will have normal priorities
		p1.thrd.start();
		p2.thrd.start();
		p3.thrd.start();
		p4.thrd.start();
		p5.thrd.start();
		p6.thrd.start();

		try {
			p1.thrd.join();
			p2.thrd.join();
			p3.thrd.join();
			p4.thrd.join();
			p5.thrd.join();
			p6.thrd.join();
		}
		catch (InterruptedException ie) {
			System.out.println("Main thread have got interrupted");
		}
		System.out.println("\n" + p1.thrd.getName() + " counted to " + p1.count);
		System.out.println("\n" + p2.thrd.getName() + " counted to " + p2.count);
		System.out.println("\n" + p3.thrd.getName() + " counted to " + p3.count);
		System.out.println("\n" + p4.thrd.getName() + " counted to " + p4.count);
		System.out.println("\n" + p5.thrd.getName() + " counted to " + p5.count);
		System.out.println("\n" + p6.thrd.getName() + " counted to " + p6.count);
	}
}

/** some os use preemptive multitasking in which each thread recieves a time
 * slice, at least occasionally. Other systems use nonpreemptive scheduling in
 * which one thread must yield execution before another thread will execute. In
 * nonpreemptive systems, it is easy for one thread to dominate, preventing
 * others from running */
