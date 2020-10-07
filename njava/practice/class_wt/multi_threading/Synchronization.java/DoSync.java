/** Doing synchronization */


// fix this program

class Operation {
	public void display(String str) {
		System.out.print("[");
		try {
			Thread.sleep(1000);
			System.out.print(str);
		catch (InterruptedException ie) { }
		System.out.print("]");
	}
}

class MyThread extends Thread {
	Operation op;
	String str = null;

	MyThread(String name, Operation op) {
		this.op = op;
		this.start();
	}

	//public static MyThread createAndStart(String threadname, String name, Operation op) {
		//MyThread mth = new MyThread(name, op);
		//mth.start();
		//return mth;
	//}

	public void run() {
		this.op.display("string is this");
	}
}

public class DoSync {
	Operation newOp = new Operation();
	MyThread.createAndStart("one", newOp);
	MyThread.createAndStart("two", newOp);
	MyThread.createAndStart("three", newOp);
}
