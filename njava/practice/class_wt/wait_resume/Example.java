/* A simple example */

class DemoSum extends Thread {
	int sum;
	DemoSum(String name) {
		super(name);
		this.sum = 0;
		start();  // start the thread
	}

	// thread execution begins here
	public void run() {
		synchronized(this) {
			for (int i = 0; i < 50; ++i) {
				sum += i;
				notify();
			}
		}
	}
}

public class Example {
	public static void main(String[] args) {
		DemoSum ob = new DemoSum("DemoThread");
		synchronized(ob) {
			try {
				//Thread.sleep(10);
				ob.wait();
			}
			catch (InterruptedException ie) {
				System.out.println("Main thread interrupted");
			}
		}
		System.out.println(ob.sum);
	}
}
