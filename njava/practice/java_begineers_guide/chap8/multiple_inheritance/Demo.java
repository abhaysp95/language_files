package multiple_inheritance;

class Gamma implements Beta, Delta {
	public void print2() {
		System.out.println("This is 2");
	}

	public int getHardyRamanujan() {
		return 1729;
	}

	// Unlike above one, which if not overriden will use the
	// 'getHardyRamanujan' from Alpha(from Beta)(as it's not in Delta), this
	// below one if not overriden will cause error.

	// try commenting this method, this method is present as default in both Alpha and Delta
	public void WhatIsMyNumber() {
		System.out.println("I'm number 2 according to time I was created");
	}
	// If commenting above, paste these two lines in main method
}

public class Demo {
	public static void main(String[] args) {
		Gamma g = new Gamma();
		Beta b;
		b = new Gamma();
		System.out.println(g.getHardyRamanujan());  // from Gamma
		g.print2();  // from Gamma
		g.WhatIsIt();  // here, WhatIsIt() from Beta should be used
		g.WhatIsMyNumber();  // from Gamma
		System.out.println("----------------");
		b.WhatIsIt();  // from Beta, although Alpha have it but Beta's takes priority
		b.WhatIsMyNumber();  // again from Beta
		System.out.println(b.getHardyRamanujan());  // from Gamma
		b.print2();  // from Gamma
		System.out.println("----------------");
		int res = Delta.callStatic();
		System.out.println("Got num: " + res);
		res = Delta.callStatic();
		System.out.println("Got num: " + res);  // number not changing cause things inside this are not static, they get reset everytime
	}
}
