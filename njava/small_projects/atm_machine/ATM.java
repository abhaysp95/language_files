package atm_machine;

import java.io.IOException;

class Test {
	private long ln = 29304029340234L;
	private long ln2 = 2093402398409234L;

	public void compare() {
		if (this.ln == this.ln2) {
			System.out.println("Equal");
		}
		else {
			System.out.println("Equal");
		}
	}
}

public class ATM {
	public static void main(String[] args) {
		Operations atmObj = new Operations();
		atmObj.doLogin();
		//Test ob = new Test();
		//ob.compare();
	}
}
