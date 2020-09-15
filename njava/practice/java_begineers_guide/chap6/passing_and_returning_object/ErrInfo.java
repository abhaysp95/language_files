// Return a programmer defined error messge

class Err {
	String msg;
	int severity;

	Err(String msg, int s) {
		this.msg = msg;
		this.severity = s;
	}
}

class ErrorInfo {
	String[] msgs = {
		"Output Error",
		"Input Error",
		"Disk Full",
		"Index Out-Of-Bounds"
	};
	int[] howBad = {3, 3, 2, 4};
	Err getErrorInfo(int index) {
		if (index >= 0 && index < msgs.length) {
			return new Err(msgs[index], howBad[index]);
		}
		else {
			return new Err("Invalid Error Code", 0);
		}
	}
}

class ErrInfo {
	public static void main(String[] args) {
		ErrorInfo err = new ErrorInfo();
		Err e;
		e = err.getErrorInfo(2);
		System.out.println(e.msg + " severity: " + e.severity);
		e = err.getErrorInfo(19);
		System.out.println(e.msg + " severity: " + e.severity);
	}
}
