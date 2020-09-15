// Using final

/* final prevents overriding, prevents inheritance, but method overloading is supported */
// You can use final with static

class ErrMsg {
	final int OUTERR = 0;
	final int INERR = 0;
	final int DISKERR = 0;
	final int INDEXERR = 0;

	String[] msgs = {
		"Output Error",
		"Input Error",
		"Disk Full",
		"Index Out-Of-Bounds"
	};

	final void print(int i) {
		System.out.println("First: " + i);
	}

	final void print(final double i) {
		System.out.println("Second: " + i);
	}

	// Return the error msg
	String getErrMsg(int i) {
		if (i >= 0 && i < msgs.length) {
			return msgs[i];
		}
		else {
			return "Invalid Error Code";
		}
	}
}

class FinalID {
	public static void main(String[] args) {
		ErrMsg err = new ErrMsg();
		System.out.println(err.getErrMsg(err.OUTERR));
		System.out.println(err.getErrMsg(err.DISKERR));
		err.print(10.0);
	}
}
