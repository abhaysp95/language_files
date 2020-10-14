// Program to simulate Traffic Light behaviour

enum TrafficLightColor {
	RED, GREEN, YELLOW
}

class TrafficLightSimulator implements Runnable {
	private TrafficLightColor tlc;
	private boolean stop = false;  // set true to stop simualtion
	private boolean changed = false;  // true when the light has changed

	TrafficLightSimulator() {
		this(TrafficLightColor.RED);
	}

	TrafficLightSimulator(TrafficLightColor init) {
		this.tlc = init;
	}

	public void run() {
		//System.out.println("inside run");
		while(!stop) {
			try {
				//System.out.println("outside run switch");
				switch(tlc) {
					case RED:
						Thread.sleep(12000); // for 12 secs
						break;
					case GREEN:
						Thread.sleep(10000); // for 10 secs
						break;
					case YELLOW:
						Thread.sleep(2000);  // for 2 secs
						break;
				}
			}
			catch (InterruptedException ie) {
				System.out.println("Exception: " + ie);
			}
			//System.out.println("calling changeColor");
			changeColor();  // change color after sleep
		}
	}

	private synchronized void changeColor() {
		//System.out.println("inside changeColor");
		switch(tlc) {
			case RED:
				this.tlc = TrafficLightColor.GREEN;
				break;
			case GREEN:
				this.tlc = TrafficLightColor.YELLOW;
				break;
			case YELLOW:
				this.tlc = TrafficLightColor.RED;
				break;
		}
		this.changed = true;
		//System.out.println("notifying now");
		notify();  // signal that light has changed
		// now this will get back to run() from where this function was invoked
	}

	synchronized void waitForChange() {
		//System.out.println("inside waitForChange");
		try {
			while(!changed) {
				wait();  // wait for light to change
				//System.out.println("wait ended");
			}
			this.changed = false;
		}
		catch(InterruptedException ie) {
			System.out.println("Exception: " + ie);
		}
	}

	synchronized TrafficLightColor getColor() {
		//System.out.println("inside getColor");
		return this.tlc;
	}

	synchronized void cancel() {
		this.stop = true;
	}
}

public class TrafficLightDemo {
	public static void main(String[] args) {
		TrafficLightSimulator t1 = new TrafficLightSimulator(TrafficLightColor.GREEN);
		Thread thrd = new Thread(t1);
		thrd.start();

		for (int i = 0; i < 9; ++i) {
			System.out.println(t1.getColor());
			//System.out.println("Calling wait for change");
			t1.waitForChange();
		}
		t1.cancel();
	}
}

/* the same thread, thrd first sleeps appropriately according to color, and
 * then schedular takes up waiting waitForChange() to execute further, and
 * still due to sleep continuing, comes to main() and then goes again to
 * waitForChange() to wait, now thrd wakes up from run() and then called
 * changeColor() */
