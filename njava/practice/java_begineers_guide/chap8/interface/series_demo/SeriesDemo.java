package series_demo;

class ByTwos implements Series {
	int start;
	int val;
	int prev;

	ByTwos() {
		start = 0;
		val = 0;
		prev = start - 2;
	}

	public int getNext() {
		prev = val;
		val += 2;
		return val;
	}

	public void reset() {
		val = start;
		prev = val - 2;
	}

	public void setStart(int x) {
		this.start = this.val = x;
		this.prev = this.val - 2;
	}

	public int getPrevious() {
		return prev;
	}
}

class ByThrees implements Series {
	int start;
	int val;

	ByThrees() {
		start = 0;
		val = 0;
	}

	public int getNext() {
		val += 3;
		return val;
	}

	public void reset() {
		val = start;
	}

	public void setStart(int x) {
		this.start = this.val = x;
	}

	public int[] getNextArray(int n) {
		// just of overriding purpose, we'll have n + 5 as difference
		int[] vals = new int[n + 5];
		for (int i = 0; i < vals.length; ++i) { vals[i] = getNext(); }
		return vals;
	}
}

public class SeriesDemo {
	public static void main(String[] args) {
		Series fs = new ByTwos();
		for (int i = 0; i < 10; ++i) {
			System.out.println(fs.getNext());
		}
		System.out.println("------------------");
		// since, fs is of Series and Series doesn't have 'getPrevious()', so type conversion to ByTwos
		System.out.println(((ByTwos) fs).getPrevious());
		System.out.println("------------------");
		// so you can just directly call this interface method or can also
		// overload according to need
		int[] gotArray = fs.getNextArray(10);
		for (int i = 0; i < 10; ++i) {
			System.out.println(gotArray[i]);
		}

		System.out.println("------------------");

		Series ss = new ByThrees();
		for (int i = 0; i < 10; ++i) {
			System.out.println(ss.getNext());
		}

		System.out.println("------------------");
		int[] newGotArray = ss.getNextArray(10);
		for (int i = 0; i < newGotArray.length; ++i) {
			System.out.println(newGotArray[i]);
		}

		System.out.println("------------------");
		int[] anotherNewGotArray = ss.skipAndGetNextArray(10, 12);
		for (int i = 0; i < anotherNewGotArray.length; ++i) {
			System.out.println(anotherNewGotArray[i]);
		}
	}
}
