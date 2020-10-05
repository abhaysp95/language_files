/* Thread Communication using notify(), wait() and notifyAll() */

/* The above methods are part of all objects(just like "synchronized") because
 * they are implemented by the Object class. These methods should be called
 * only from within a synchronized context. Here is how they are used. When a
 * thread is temporarily blocked from running, it calls wait(). This causes the
 * thread to go sleep and the monitor for that object to be released, allowing
 * another thread to use the object. At a later point, the sleeping thread is
 * awakened when some other thread enters the same monitor and calls notify()
 * or notifyAll() */

/* Various forms:
   final void wait() throws InterruptedException
   final void wait(long millis) throws InterruptedException
   final void wait(long millis, int nanos) throws InterruptedException

   final void notify()
   final void notifyAll()
*/

/* A call to notify() resumes one waiting thread, whereas notifyAll() notifies
 * all threads, with the scheduler determining which thread gains access to the
 * object */

/* Although, wait() normally waits until notify() and notifyAll() is called,
 * there is possibility that in very rare cases the waiting thread could be
 * awakened due to a "spurious wakeup". The conditions that lead to a spurious
 * wakeup are complex. However, due to this, Java API documentation recommends
 * that because of the remote possibility of a spurious wakeup, calls to wait()
 * should take place within a loop that checks the condition on which the
 * thread is waiting */


// Use wait() and notify() to create a ticking clock

class TickTock {
	String state;  // contains the state of the clock

	synchronized void tick(boolean running) {
		if(!running) {  // stop the clock
			state = "ticked";
			notify();  // notify any waiting thread
			return;
		}
		System.out.print("Tick ");
		try {
			Thread.sleep(500);
			// adding sleep will not affect, as this method is synchronized
			// method so no other thread can access this object until it is
			// unlocked through wait() and their isn't any other thread which
			// is doing something else
		}
		catch(InterruptedException ie) {
			System.out.println("Interruption in tick during sleep");
		}
		state = "ticked";  // set the current state to ticked
		notify();  // let tock() run(tick() notifies tock())
		try {
			while (!state.equals("tocked")) {
				wait();  // wait for tock() to complete
			}
			// I think the above loop is not for dealing with spurious
			// condition, it's just for checking the state or maybe this is
			// doing both ?
		}
		catch(InterruptedException ie) {
			System.out.println("Thread interrupted");
		}
	}

	synchronized void tock(boolean running) {
		if(!running) {
			state = "tocked";
			notify();  // notify any awaiting threads
			return;
		}
		System.out.println("Tock");
		try {
			Thread.sleep(500);
		}
		catch(InterruptedException ie) {
			System.out.println("Interruption in tick during sleep");
		}
		state = "tocked";  // set the current state to tocked
		notify();  // let tick() run(tock() notifies tick())
		try {
			while(!state.equals("ticked")) {
				wait();  // wait for tick() to complete
			}
		}
		catch(InterruptedException ie) {
			System.out.println("Thread interrupted");
		}
	}
}

class MyThread implements Runnable {
	Thread thrd;
	TickTock ttOb;

	// Construct a new thread
	MyThread(String name, TickTock tt) {
		this.thrd = new Thread(this, name);
		this.ttOb = tt;
	}

	// factory method to create and start thread
	public static MyThread createAndStart(String name, TickTock tt) {
		MyThread mth = new MyThread(name, tt);
		mth.thrd.start();
		return mth;
	}

	// Entry point of thread
	public void run() {
		System.out.println("Starting: " + this.thrd.getName());
		if(this.thrd.getName().compareTo("Tick") == 0) {
			for(int i = 0; i < 5; ++i) {
				//System.out.println("Inside tick's for");
				this.ttOb.tick(true);
			}
			//System.out.println("Outside tick's for");
			this.ttOb.tick(false);
		}
		else {
			for(int i = 0; i < 5; ++i) {
				//System.out.println("Inside tock's for");
				this.ttOb.tock(true);
			}
			//System.out.println("Outside tock's for");
			this.ttOb.tock(false);
		}
	}
}

public class ThreadCommunication {
	public static void main(String[] args) {
		TickTock tt = new TickTock();
		MyThread mt1 = MyThread.createAndStart("Tick", tt);
		MyThread mt2 = MyThread.createAndStart("Tock", tt);

		try {
			mt1.thrd.join();
			mt2.thrd.join();
		}
		catch(InterruptedException ie) {
			System.out.println("Main thread interrupted");
		}
	}
}
